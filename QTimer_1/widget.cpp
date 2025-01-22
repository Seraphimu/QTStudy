#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //在构造函数中初始化QTimer
    myQTimer = new QTimer();

    //1. 初始化显示图片
    QPixmap pix("C:/Users/ATRI/MySpace/Temp/TextQt/1.jpg");
    ui->label->setPixmap(pix);

    //绑定QTimer信号与处理它的槽函数
    connect(myQTimer, &QTimer::timeout, this, &Widget::myQTimerSlot);

    //初始化picId
    picId = 2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_released()
{
    //启动定时器
    myQTimer->start(TIMEOUT);
}

void Widget::myQTimerSlot() {
    //处理myQTimer发出的信号的槽函数
    QString picPath = "C:/Users/ATRI/MySpace/Temp/TextQt/";
    picPath += QString::number(picId);
    picPath += ".jpg";

    QPixmap pix(picPath);
    ui->label->setPixmap(picPath);

    picId = picId % 23 + 1;
}

void Widget::on_pauseButton_released()
{
    myQTimer->stop();
}

//要点
//QTimer类型指针的声明
//QTimer函数处理需要使用connect()连接
//使用start(TIMEOUT)函数让定时器开始后，每过一段时间就执行一遍槽函数
//使用stop()函数来关闭定时器工作
//图片id刻要初始化
