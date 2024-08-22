#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //光标在账号和密码框时，按回车就可以触发登陆
    connect(ui->userIdLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
    connect(ui->passwdLineEdit, &QLineEdit::returnPressed, this, &Widget::on_loginButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginButton_clicked()
{
    QString userId = ui->userIdLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();

    QMessageBox * loginStatus;
    if (userId == "汪伟" && passwd == "几把格调") {
        loginStatus->information(this, "登陆成功", "给汪伟几把格调！");
    }
    else {
        loginStatus->information(this, "登陆失败", "还得给汪伟几把格调！");
    }
}

//总结
/*
学了信号与槽的实现：
方法一：右键，转到槽
方法二：用connect()方法 + 宏实现
方法三：用connect()方法 + 方法指针实现
方法四：用connect()方法 + 对象指针
QMessageBox类中的当information()方法：
void QMessageBox::information(pointerToObject, QString leftSup, QString indicationInfo);
QString为QT自己定义的一种字符串类型
用LineEdit类的text()方法可以获得对象的文本
QString str = ui->lineEdit->text();

UI布局
可以把几个对象选中，点一下垂直、水平对齐就可以自动水平、垂直对齐了。
*/
