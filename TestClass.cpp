#include "TestClass.h"

TestClass::TestClass() : Qt3DWindow()
{
  root = nullptr;
}

void TestClass::draw()
{
  if( root ) return;

  root = new Qt3DCore::QEntity;

  setRootEntity( root );

  Qt3DCore::QEntity     *cube     = new Qt3DCore::QEntity{ root };
  Qt3DCore::QComponent  *material = new Qt3DExtras::QPhongMaterial{ root };
  Qt3DCore::QComponent  *mesh     = new Qt3DExtras::QCuboidMesh{ root };

  cube->addComponent( material  );
  cube->addComponent( mesh      );

  Qt3DCore::QEntity     *sphere   = new Qt3DCore::QEntity{ root };
  Qt3DCore::QComponent  *meshS    = new Qt3DExtras::QSphereMesh{ root };
  Qt3DCore::QTransform  *tran     = new Qt3DCore::QTransform{ root };

  tran->setTranslation( QVector3D{ 5, 5, 5 } );

  sphere->addComponent( material  );
  sphere->addComponent( meshS     );
  sphere->addComponent( tran      );

  camera()->setPosition( QVector3D{ 0, 15, 15 } );
  camera()->setViewCenter( QVector3D{ 5, 0, 0 } );
}
