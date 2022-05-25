#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);
    QMenu * fileMenu = bar->addMenu("文件");
    bar->setVisible(true);

    //添加子菜单
    QAction *newAction = fileMenu->addAction("新建文件");
    newAction->setIcon(QIcon(":imgs/icons8-export.png"));
    newAction->setShortcut(Qt::CTRL | Qt::Key_E);

    //添加子菜单
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开文件");
    openAction->setIcon(QIcon(":imgs/icons8-exit.png"));
    openAction->setShortcut(Qt::CTRL | Qt::Key_Q);

    QMenu *childMenu = new QMenu();
    QAction *set_file = new QAction(childMenu);
    set_file->setText("设置文件内容");

    childMenu->addAction(set_file);

    QAction *read_file = new QAction(childMenu);
    read_file->setText("设置文件内容");

    childMenu->addAction(read_file);


    openAction->setMenu(childMenu);
    fileMenu->addMenu(childMenu);


    fileMenu = bar->addMenu("Bus");

    QAction *con = fileMenu->addAction("connect");
    QIcon icaonConnect;
    icaonConnect.addFile(":imgs/icons8-disconnected.png",QSize(),QIcon::Normal,QIcon::Off);
    icaonConnect.addFile(":imgs/icons8-connected.png",QSize(),QIcon::Normal,QIcon::On);
    con->setIcon(icaonConnect);
    con->setCheckable(true);
    con->setStatusTip("connect/disconnect bus");
    fileMenu->addAction(con);



    // 创建工具栏(可屏蔽掉,屏蔽掉后底部将失去控件栏位)
    QToolBar *toolBar = new QToolBar(this); //创建工具栏
    addToolBar(Qt::TopToolBarArea,toolBar);
    toolBar->setFloatable(false);
    toolBar->setMovable(false);

    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    toolBar->addSeparator();
    toolBar->addAction(con);


    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    connect(newAction,&QAction::triggered,this,[](){
        std::cout << "new file slot" << std::endl;
    });

    connect(openAction,&QAction::triggered,this,[=](){
        std::cout << "open file slot" << std::endl;
    });




    ui->dockWidget->setWidget(new QPushButton("hhh"));




}

MainWindow::~MainWindow()
{
    delete ui;
}

