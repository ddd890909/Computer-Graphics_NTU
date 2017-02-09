/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "glwidget.h"
#include "controlpanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();

private:
    void createActions();
    void createMenus();

    GLWidget *glWidget;
    ControlPanel *panel;
    QMenu *fileMenu;
    QAction *openAct;
    QAction *exitAct;
};

#endif // MAINWINDOW_H
