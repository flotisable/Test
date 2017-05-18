#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QtWidgets>
#include <QDebug>

#include <Qt3DExtras>
#include <Qt3DCore>

class TestClass : public Qt3DExtras::Qt3DWindow
{
  Q_OBJECT

  public:

    TestClass();

    void draw(); // draw a sphere and a cube

  private:

    Qt3DCore::QEntity *root;
};

#endif // TESTCLASS_H
