#include "MainWindow.h"

#define EMBEDED_IN_QWIDGET

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
  test = new TestClass;

  test->draw();
  setupLayout();
  setupConnect();
  initControl();

#ifndef EMBEDED_IN_QWIDGET // sperate the Qt3D window from widget
  test->show();
  QObject::connect( qApp, &QApplication::aboutToQuit, [&](){ delete test; } );
#endif
}

void MainWindow::setupLayout()
{
  QHBoxLayout *posEditLayout = new QHBoxLayout;

  posLabel = new QLabel{ "pos" };
  posXEdit = new QLineEdit;
  posYEdit = new QLineEdit;
  posZEdit = new QLineEdit;

  posEditLayout->addWidget( posLabel );
  posEditLayout->addWidget( posXEdit );
  posEditLayout->addWidget( posYEdit );
  posEditLayout->addWidget( posZEdit );

  QHBoxLayout *viewEditLayout = new QHBoxLayout;

  viewLabel = new QLabel{ "view" };
  viewXEdit = new QLineEdit;
  viewYEdit = new QLineEdit;
  viewZEdit = new QLineEdit;

  viewEditLayout->addWidget( viewLabel );
  viewEditLayout->addWidget( viewXEdit );
  viewEditLayout->addWidget( viewYEdit );
  viewEditLayout->addWidget( viewZEdit );

  captureButton = new QPushButton{ "capture"  };

  QVBoxLayout *controlLayout = new QVBoxLayout;

  controlLayout->addLayout( posEditLayout   );
  controlLayout->addLayout( viewEditLayout  );
  controlLayout->addWidget( captureButton   );

  QHBoxLayout *layout = new QHBoxLayout;

  layout->addLayout( controlLayout );
#ifdef EMBEDED_IN_QWIDGET
  /*
   * embed Qt3D window to widget
   * sometimes cause the app crash when exit
  */
  layout->addWidget( QWidget::createWindowContainer( test ), 1 );
#endif
  setLayout( layout );
}

void MainWindow::setupConnect()
{
  auto setPos = [&]()
                {
                  test->camera()->setPosition( QVector3D{ posXEdit->text().toFloat(),
                                                          posYEdit->text().toFloat(),
                                                          posZEdit->text().toFloat(),
                                                          } );
                };

  auto setView = [&]()
                {
                  test->camera()->setViewCenter( QVector3D{ viewXEdit->text().toFloat(),
                                                            viewYEdit->text().toFloat(),
                                                            viewZEdit->text().toFloat(),
                                                            } );
                };

  QObject::connect( posXEdit, &QLineEdit::editingFinished, setPos );
  QObject::connect( posYEdit, &QLineEdit::editingFinished, setPos );
  QObject::connect( posZEdit, &QLineEdit::editingFinished, setPos );
  QObject::connect( viewXEdit, &QLineEdit::editingFinished, setView );
  QObject::connect( viewYEdit, &QLineEdit::editingFinished, setView );
  QObject::connect( viewZEdit, &QLineEdit::editingFinished, setView );
  QObject::connect( captureButton, &QPushButton::clicked,
                    [&]()
                    {
                      test->screen()->grabWindow( test->winId() ).save( "test.png" );
  } );
}

void MainWindow::initControl()
{
  posXEdit->setText( QString{ "%1" }.arg( test->camera()->position().x() ) );
  posYEdit->setText( QString{ "%1" }.arg( test->camera()->position().y() ) );
  posZEdit->setText( QString{ "%1" }.arg( test->camera()->position().z() ) );
  viewXEdit->setText( QString{ "%1" }.arg( test->camera()->viewCenter().x() ) );
  viewYEdit->setText( QString{ "%1" }.arg( test->camera()->viewCenter().y() ) );
  viewZEdit->setText( QString{ "%1" }.arg( test->camera()->viewCenter().z() ) );
}
