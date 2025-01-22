#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_commitButton_released()
{
    //打开一个进程
    QString command = ui->cmdLineEdit->text();
    //为什么使用QProcess myProcess;创建对象后调用myProcess.start(cmd);会显示进程在运行中？？？
    QProcess * myProcess = new QProcess();
    myProcess->start(command);
}


void Widget::on_cancelButton_released()
{
    //关闭该进程
    this->close();
}


void Widget::on_browseButton_released()
{
    //弹出一个对话框
    QMessageBox::information(this, "浏览", "浏览完成");
}

