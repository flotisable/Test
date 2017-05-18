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
    void initControl  ();

    TestClass *test; // Qt3D window

    // for setup camera position
    QLabel    *posLabel;
    QLineEdit *posXEdit;
    QLineEdit *posYEdit;
    QLineEdit *posZEdit;
    // end for setup camera position

    // for setup camera view center
    QLabel    *viewLabel;
    QLineEdit *viewXEdit;
    QLineEdit *viewYEdit;
    QLineEdit *viewZEdit;
    // end for setup camera view center

    QPushButton *captureButton; // to capture the image
};

#endif // MAINWINDOW_H
