#ifndef WIDGET_H
#define WIDGET_H

#define TIMEOUT 1 * 1000

#include <QWidget>

//1. 包含QTimer记时器的头文件
#include <QTimer>

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

private slots:
    void on_startButton_released();
    void timerSlot();

    void on_stopButton_released();

private:
    Ui::Widget *ui;
    //2. 增加一个QTimer类型的指针成员
    QTimer * timer;

    int picId;
};
#endif // WIDGET_H
