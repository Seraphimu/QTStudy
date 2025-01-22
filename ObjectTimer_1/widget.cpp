#include "widget.h"
#include "ui_widget.h"

//电子相册
//1. 在初始状态下显示第一张图片
//2. 按下开始按钮后，每隔一段时间换下一张图片（开启定时器）
//3. 按下暂停按钮后，停止动作（关闭定时器）

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始状态下显示图片
    //加载第一张图片
    QPixmap pix("C:/Users/ATRI/MySpace/Temp/TextQt/1.jpg");
    //把图片贴到Label上去
    ui->label->setPixmap(pix);
    //初始化picId，按下定时器从第二张开始向后播放
    picId = 2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_released()
{
    //==========================================================
    //踩坑点一
    //==========================================================
    //开启定时器，并用startTimerId接收它
    startTimerId = this->startTimer(TIMEOUT);
}

void Widget::timerEvent(QTimerEvent *event) {
    //当前事件如果是点击开始按键发出的就执行以下代码
    if (event->timerId() == startTimerId) {
        //实现图片的切换，按下“开始按钮”后，每过一段时间这个函数就会被执行一次
        //1. 首先要显示图片，构建出图片的路径
        QString picPath = "C:/Users/ATRI/MySpace/Temp/TextQt/";
        //把整形转换为QString型，再拼接到picPath上来
        picPath += QString::number(picId);
        //接文件后缀
        picPath += ".jpg";

        //2. 显示图片
        QPixmap pix(picPath);
        ui->label->setPixmap(pix);

        //3. 实现图片Id的自增
        //1 ~ 23
        picId = picId % 23 + 1;
    }
    else {
        return;
    }
}

void Widget::on_pauseButton_released()
{
    //停止定时器
    this->killTimer(startTimerId);
}

//要点：
//1. 启动定时器：int TimerId = this->startTimer(TIMEOUT);
//2. 定时器发出事件
//重写timerEvent()函数
//event->timerId() == TimerId则触发定时器
//3. 关闭定时器this->killTimer(TimerId)
