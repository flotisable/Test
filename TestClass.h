#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QtWidgets>
#include <QDebug>

class TestClass : public QGraphicsView
{
  Q_OBJECT

  public:

    TestClass( QWidget *parent = nullptr );

  public slots:

    void addItem();

  private:

    QGraphicsScene *scene;
};

#endif // TESTCLASS_H
