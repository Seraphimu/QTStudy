#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QMouseEvent>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

private slots:
    //新建
    void newActionSlot();
    //打开
    void openActionSlot();
    //保存
    void saveActionSlot();

    //重写
    //重写的函数名不能错注意
    virtual void keyPressEvent(QKeyEvent * ev);

    virtual void mousePressEvent(QMouseEvent * ev);
};
#endif // MAINWINDOW_H
