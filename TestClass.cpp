#include "TestClass.h"

#include <cstdlib>

TestClass::TestClass( QWidget *parent ) : QGraphicsView{ parent }
{
  scene = new QGraphicsScene{ this };

  setScene( scene );
}

void TestClass::addItem()
{
  double x = rand() % 100;
  double y = rand() % 100;
  double w = rand() % 100;
  double h = rand() % 100;

  scene->addRect( x, y , w, h, QPen{ Qt::red } );
  fitInView( scene->sceneRect() );
}
