#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //在构造函数中初始化Id和定时器指针
    startQTimer = new QTimer();
    picId = 2;

    //初始化显示图片
    QPixmap pix("C:/Users/ATRI/MySpace/Temp/TextQt/1.jpg");
    ui->label->setPixmap(pix);

    //连接QTimer信号与槽
    connect(startQTimer, &QTimer::timeout, this, &Widget::startQTimerSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startQTimerSlot() {
    //处理
    //构建路径
    QString picPath = "C:/Users/ATRI/MySpace/Temp/TextQt/";
    picPath += QString::number(picId);
    picPath += ".jpg";

    QPixmap pix(picPath);
    ui->label->setPixmap(pix);

    picId = picId % 23 + 1;
}

void Widget::on_startButton_released()
{
    //启动定时器
    startQTimer->start(2000);
}


void Widget::on_pauseButton_released()
{
    startQTimer->stop();
}

