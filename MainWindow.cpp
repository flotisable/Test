#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
  test      = new TestClass;
  addButton = new QPushButton{ "add" };

  setupLayout ();
  setupConnect();
}

void MainWindow::setupLayout()
{
  QVBoxLayout *layout = new QVBoxLayout;

  layout->addWidget( test       );
  layout->addWidget( addButton  );

  setLayout( layout );
}

void MainWindow::setupConnect()
{
  connect( addButton, &QPushButton::clicked, test, &TestClass::addItem );
}
