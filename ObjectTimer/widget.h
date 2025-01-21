#ifndef WIDGET_H
#define WIDGET_H

//定时器
#define TIMEOUT 3 * 1000

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写timeEvent函数，该函数是个父类中的虚函数，继承需要重写
    virtual void timerEvent(QTimerEvent * event);

private slots:
    void on_startButton_released();

    void on_stopButton_released();

private:
    Ui::Widget *ui;

    //定时器编号
    int myTimerId;
    //图片编号
    int picId;
};
#endif // WIDGET_H
