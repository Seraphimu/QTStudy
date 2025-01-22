#ifndef WIDGET_H
#define WIDGET_H
#define TIMEOUT 2 * 1000

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

private slots:
    void on_startButton_released();
    void myQTimerSlot();

    void on_pauseButton_released();

private:
    Ui::Widget *ui;
    //图片Id
    int picId;
    //定时器指针
    QTimer * myQTimer;
};
#endif // WIDGET_H
