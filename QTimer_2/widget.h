#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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

private:
    Ui::Widget *ui;
    //QTimer定时器指针
    QTimer * startQTimer;
    //图片Id
    int picId;
private slots:
    void startQTimerSlot();
    void on_startButton_released();
    void on_pauseButton_released();
};
#endif // WIDGET_H
