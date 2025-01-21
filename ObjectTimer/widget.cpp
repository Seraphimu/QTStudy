#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设图片id初值
    picId = 2;

    //写在构造函数中，程序一启动就可以看见（可当作默认状态）
    //创建一个Pixmap对象，把图片路径作为构造函数的参数传入
    QPixmap pix("C:/Users/ATRI/MySpace/Temp/TextQt/1.jpg");
    //把图片放在label上
    // void setPixmap(Qpixmap pix);
    ui->label->setPixmap(pix);

}

Widget::~Widget()
{
    delete ui;
}

//点击开始按钮，启动计时器
void Widget::on_startButton_released()
{
    //startTimer是QObject类下的，Widget : QWidget : QObject继承关系，所以可以用this指针来调用
    //开启定时器，返回定时器编号
    myTimerId = this->startTimer(TIMEOUT);
}

//根据定时器启动事件
void Widget::timerEvent(QTimerEvent *event) {
    //判断定时器
    if (event->timerId() != myTimerId) {
        return;
    }

    //构建路径
    // QString picPath = "C:/Users/ATRI/MySpace/Temp/TextQt";       //少了一个小斜杠
    QString picPath = "C:/Users/ATRI/MySpace/Temp/TextQt/";
    picPath += QString::number(picId);
    picPath += ".jpg";

    //设置图片
    QPixmap pix(picPath);
    ui->label->setPixmap(pix);

    picId++;
    if (23 == picId) {
        picId = 1;
    }
}

void Widget::on_stopButton_released()
{
    //停止定时器
    this->killTimer(myTimerId);
}

