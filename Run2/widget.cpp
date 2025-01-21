#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    // connect(ui->cmdLineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));
    // connect(发出者, 类型, 接收者，处理方法)
    //这里发出者是cmdLineEdit, 即输入框，信号是回车键，接收都是自己，调用的槽函数是释放时打开
    //用宏
    // connect(ui->cmdLineEdit, SIGNAL(returnPressed()), this, SLOT(on_openButton_released()));
    // connect(ui->openButton, SIGNAL(returnPressed()), this, SLOT(on_openButton_released()));

    //用指针
    //槽函数都写在Widget类的private solts:里面
    connect(ui->cmdLineEdit, &QLineEdit::returnPressed, this, &Widget::on_openButton_released);

    //如果要处理的内容很简单，不想单独开一个槽函数，完全可以直接在connect()函数中写出来
    //connect(发出者，类型，[this] {操作})
    connect(ui->browseButton, &QPushButton::clicked, [this]
    {
        //information(父类, 标题，提示框内容)
        //QMessageBox::information()是static类型的成员，只属于类，而不属于任何一个实例，故，不需创建对象就可调用
        QMessageBox::information(this, "信息", "点击浏览");
    });


    //附加：按esc退出

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openButton_released()
{
    //To Do
    //既然点击了打开按键，按照Windows的cmd应该会打开一个程序，比如notepad记事本
    //这里引入一个类：QProcess类，其成员函数start(QString process_name)可以根据其参数（字符串）启动一个进程
    //这里又要引入一个QString类，该类有点像C++中的string类

    //好，引入了这两个类，那么我们的字符串从哪里来？当然是从cmdLineEdit，即那个输入框来了，
    //这个输入框是一个QLineEdit类型的对象，该类有一个成员函数QString text()可以以QString类型返回该输入行中的内容

    //获取输入，ui是整个界面的指针，在这个界面上的指针都可以当作是ui的一个一个一个成员啊
    //用command这个变量接收该内容
    QString command = ui->cmdLineEdit->text();

    //创建一个QProcess对象
    QProcess * myProcess = new QProcess();

    //调用QProcess类的start函数，并把command作为参数传递给它，让它启动该进程
    myProcess->start(command);


    //-----------------------------------------------------------------
    //不足
    //这里没有考虑到空命令和错误命令的情况
    //也没有考虑到myProcess指针释放的情况
}
















void Widget::on_cancelButton_released()
{
    //To Do
    //点击并释放该按键时，关闭该进程
    // close();
    //直接调用close，或者this->close()即可
    this->close();
}

