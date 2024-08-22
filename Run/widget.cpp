#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //界面指针ui
    ui->setupUi(this);


    //连接信号与槽
    //发出者，信号类型，接收者，处理方法
    //
    // connect(ui->cmdLineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));
    //同上作用，发出者为cmdLineEdit对象，发出的信号为按下回车，接收者是本对象，作出的回应是用on_commitButton_clicked()方法
    //取其成员函数的指针
    connect(ui->cmdLineEdit, &QLineEdit::returnPressed, this, &Widget::on_commitButton_clicked);

    connect(ui->cancelButton, &QPushButton::clicked, this, &Widget::on_cancelButton_clicked);

    connect(ui->browseButton, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "信息", "点击浏览");
    });
}

Widget::~Widget()
{
    delete ui;
}

//按钮commitButton点击后执行的槽函数
void Widget::on_commitButton_clicked()
{
    //获取cmdLineEdit的数据
    //之前把LineEdit类用成了TextEdit类，搞得text()方法没调用成功，回头查查这两个文本框的区别
    QString program = ui->cmdLineEdit->text();
    //创建Process对象
    QProcess *myProcess = new QProcess(this);
    //
    myProcess->start(program);

}

void Widget::on_cancelButton_clicked() {
    // this->close();

    //this是类的类型，也是指向当前这个由本类创建出的对象的指针。
    Widget * thisP = this;
    thisP->close();
}


/*
 * QProcess类的对象可以根据字符串运行windows的程序
 * //分配空间
 * QProcess * myProcess = new Process(this);
 * myProcess->start(programName);
 *
 * /


