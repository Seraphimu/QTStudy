#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //新建操作信号与槽连接
    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);
    //打开操作信号与槽连接
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::openActionSlot);
    //保存函数信号与槽连接
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//新建函数实现
void MainWindow::newActionSlot() {
    //需要清空TextEdit控件上的内容，
    ui->textEdit->clear();
    //并修改标题为 “新建文本文档”
    this->setWindowTitle("新建文本文档");
}
//打开函数实现
void MainWindow::openActionSlot() {
    //弹出一个打开文件的对话框
    QString fileName = QFileDialog::getOpenFileName(this, "请选择一个一个一个文件哼哼哼啊啊啊啊", "./");

    //未选择文件：警报
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "未选择一个一个一个文件哼哼哼啊啊啊啊");
    }
    //选择一个文件
    else {
        //1. 打开文件，把文件内容读入一个变量中去
        QFile file(fileName);
        //以只读方式打开文件
        file.open(QIODevice::ReadOnly);
        //把文件内容读入到一个变量中去
        QByteArray ba = file.readAll();

        //2. 把变量中的内容放在TextEdit控件上去
        //利用构造函数转换数据类型为QString
        ui->textEdit->setText(QString(ba));

        //3. 关闭文件，小心驶得万年船
        file.close();
    }
}
//保存函数实现
void MainWindow::saveActionSlot() {
    //1.打开一个保存文件对话框
    QString fileName = QFileDialog::getSaveFileName(this, "请保存一个一个一个文件哼哼哼啊啊啊", "./");

    //2. 把控件上的内容读入到一个变量中去
    QString content = ui->textEdit->toPlainText();

    //3. 打开文件，并把变量中的内容写入到文件中
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    //利用toLatin1()方法或者toLocal8Bit()方法转换数据类型
    // QByteArray ba = content.toLocal8Bit();
    QByteArray ba = content.toLatin1();
    file.write(ba);

    //4. 关闭文件
    file.close();
}
