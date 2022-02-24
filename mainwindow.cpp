#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draglabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(
                Qt::WindowCloseButtonHint|
                Qt::WindowMinimizeButtonHint|
                Qt::Window|
                Qt::MSWindowsFixedSizeDialogHint
                );
    QLabel* label = new DragLabel(this);
    setCentralWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

