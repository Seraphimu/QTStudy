#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //绑定
    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::newActionSlot() {
    ui->textEdit->clear();
    //改个标题
    this->setWindowTitle("新建文本文档");
}

void MainWindow::openActionSlot() {
    //调出一个打开文件的对话框
    QString fileName = QFileDialog::getOpenFileName(this, "请打开一个一个一个文件哼哼哼啊啊啊啊", "./");

    //选择文件
    //未选择文件报个警告
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个一个一个文件哼哼哼啊啊啊啊");
    }
    //己选一个文件
    //1. 读取文件中的内容到一个变量中
    //2. 从这个变量中把内容读到QT控件上
    else {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        //用ba临时存储一下内容
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot() {
    //1. 打开文件保存选项
    QString fileName = QFileDialog::getSaveFileName(this, "请保存文件", "./");
    //2. 创建一个文件对象，接收控件上的内容
    QString content = ui->textEdit->toPlainText();
    //3. 打开文件，并写入该内容
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QByteArray ba = content.toLatin1();
    file.write(ba);
    file.close();
}
