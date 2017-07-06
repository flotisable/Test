#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "TestClass.h"

class MainWindow : public QWidget
{
  Q_OBJECT

  public:

    explicit MainWindow(QWidget *parent = 0);

  private:

    void setupLayout  ();
    void setupConnect ();

    TestClass *test;

    QPushButton *addButton;
};

#endif // MAINWINDOW_H
