#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(250, 300);
    this->setMinimumSize(250, 300);

    this->setWindowTitle("计算器");

    QFont f("微软雅黑", 14);  //字体对象
    ui->mainLineEdit->setFont(f);

    //放图标，路径注意转义字符
    // QIcon con("../img/icons/BackSpaceIcon.png");

    QIcon con("C:/Users/ATRI/Files/Projects/QTStudy/Calculator/img/icons/BackSpaceIcon.png");
    ui->deleteButton->setIcon(con);


    //改变按钮背景
    ui->equalButton->setStyleSheet("background:green");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneButton_clicked()
{
    expression += "1";
    //显示出来
    ui->mainLineEdit->setText(expression);
}


void Widget::on_twoButton_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_subButton_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}




void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_clearButton_clicked()
{
    //清空字符串
    expression.clear();
    //清空界面显示
    ui->mainLineEdit->clear();
}


void Widget::on_deleteButton_clicked()
{
    //把结尾删除一个（尾删）
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_equalButton_clicked()
{
    //用栈实现四则运算
    // QStack s_num, s_opt;

    // char opt[128] = {0};
    // int i = 0, tmp = 0, num1, num2;
    // //把QString转换成char *
    // QByteArray ba;
    // ba.append(expression);  //转换成QByteArray
    // strcpy(opt, ba.data()); //把QByteArray转换成const char *

    // while (opt[i] != '\0' || s_opt.empty() != true) {
    //     if (opt[i] >= '0' && opt[i] <= '9') {
    //         tmp = tmp * 10 + opt[i] - '0';
    //         i++;
    //         if (opt[i] < '0' || opt[i] > '9') {
    //             s_sum.push(tmp);
    //             tmp = 0;
    //         }
    //     }
    //     else {
    //         if (s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top()))
    //     }
    // }
}

