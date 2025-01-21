#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //3. 在构造函数中初始化这个QTimer类型的指针
    timer = new QTimer();

    //4. 显示最开始的图片
    QImage img;
    img.load("C:/Users/ATRI/MySpace/Temp/TextQt/1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //初始化picId
    picId = 2;

    //连接计时器信号与处理事件的槽函数
    connect(timer, &QTimer::timeout, this, &Widget::timerSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_released()
{
    //To Do
    //点击开始按钮时，启动定时器
    timer->start(TIMEOUT);
}

void Widget::timerSlot() {
    //To Do
    //1. 构建路径
    QString path = "C:/Users/ATRI/MySpace/Temp/TextQt/";
    path += QString::number(picId);
    path += ".jpg";

    //2. 更新图片显示
    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    //3. 更新路径
    picId++;
    if (picId == 23) {
        picId = 1;
    }
}

void Widget::on_stopButton_released()
{
    //点击并释放关闭按钮时，关闭定时器
    timer->stop();
}

