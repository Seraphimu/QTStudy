#ifndef WIDGET_H
#define WIDGET_H
#define TIMEOUT 2 * 1000
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
    //timerEvent()方法
    virtual void timerEvent(QTimerEvent * event);

private slots:
    void on_startButton_released();

    void on_pauseButton_released();

private:
    Ui::Widget *ui;
    //自定义的定时器Id和图片Id
    int startTimerId;
    int picId;
};
#endif // WIDGET_H
