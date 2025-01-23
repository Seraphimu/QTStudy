#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

//键鼠事件
#include <QKeyEvent>
#include <QMouseEvent>

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
    // 新建文本文档
    // 初始化状态
    void newActionSlot();

    //打开操作
    void openActionSlot();

    //保存操作
    void saveActionSlot();

    //键盘事件虚函数
    virtual void keyPressEvent(QKeyEvent * ev);
    //鼠标事件虚函数
    virtual void mousePressEvent(QMouseEvent * ev);
};
#endif // MAINWINDOW_H
