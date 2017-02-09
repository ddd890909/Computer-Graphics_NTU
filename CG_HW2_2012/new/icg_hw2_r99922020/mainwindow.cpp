/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    glWidget = new GLWidget;
    panel = new ControlPanel;
    panel->setGLWidget(glWidget);

    createActions();
    createMenus();
    (void)statusBar();
    QWidget *central = new QWidget;
    setCentralWidget(central);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(glWidget);
    layout->addWidget(panel);
    central->setLayout(layout);

    setMinimumSize(QSize(1200, 850));
    setMaximumSize(QSize(1200, 850));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

MainWindow::~MainWindow()
{
    delete glWidget;
    delete panel;
    delete fileMenu;
    delete openAct;
    delete exitAct;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        if(!glWidget->loadModel(fileName)) {
            QMessageBox::warning(this, tr("Error"),
                         tr("Cannot read file %1.")
                         .arg(fileName));
            return;
        }
        glWidget->updateGL();
        statusBar()->showMessage(tr("File loaded"), 2000);
    }
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a tri model"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
}
