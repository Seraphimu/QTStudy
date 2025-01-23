#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在构造函数中绑定新建信号与槽函数
    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);
    //打开
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::openActionSlot);
    //可在
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::newActionSlot() {
    //To Do
    //做一个清空文本的操作，显示一个空文档

    ui->textEdit->clear();

    this->setWindowTitle("新建文本文档");
}

void MainWindow::openActionSlot() {
    //To Do
    //打开一个文件选择框，选中可打开文件

    //弹出 “文件打开” 选择对话框，并获取当前路径为一个QString类型的对象，并指定打开类型为*cpp
    QString filePath = QFileDialog::getOpenFileName(this, "请选择一个文件", "./", "*.cpp");

    //文件为空，如果在对话框中未选择文件，则会弹出这么一个警告
    if (filePath.isEmpty()) {
        //参数：父类、标题、内容
        QMessageBox::warning(this, "警告", "请选择一个一个一个文件啊");
    }
    //选中一个文件，并打开它
    else {
        //打开文件
        QFile file(filePath);
        //以只读方式打开
        file.open(QIODevice::ReadOnly);
        //读取文件
        //readAll()方法返回一个QByteArray类型的字符串
        //用ba接收文件内容
        QByteArray ba = file.readAll();

        //接收到内容之后，把它放在TextEdit上
        //由于ba上一个QByteArray类型的对象，需要先把它转成QString类型再传入参数
        //可以利用QString类的构造函数来转换数据类型（实测不转换也能用，可能有隐式转换罢）
        ui->textEdit->setText(QString(ba));

        //养成一个随手关闭文件的好习惯
        file.close();
    }
}

void MainWindow::saveActionSlot() {
    //To Do
    //1. 打开一个文件保存对话框
    QString filePath = QFileDialog::getSaveFileName(this, "请保存文件", "./", "*.cpp");

    //2. 判断是否选择了文件
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请保存文件");
    }
    else {
        // 3. 打开文件
        QFile file(filePath);
        file.open(QIODevice::WriteOnly);
        // 4. 读取TextEdit上的内容
        QString content = ui->textEdit->toPlainText();
        // 5. 把QString类型的content转换为QByteArray类型
        QByteArray ba = content.toLatin1();
        // QByteArray ba = content.toLocal8Bit();

        // 6. 把内容写入到文件中
        file.write(ba);

        // 7. 关闭文件
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent * ev) {
    //按下Ctrl + S实现保存
    //检测，如果按下的是Ctrl + S，则调用saveActionSlot()
    //key()函数和modifiers()函数可以检测按下的是哪些键盘
    if (ev->key() == Qt::Key_S && ev->modifiers() == Qt::ControlModifier) {
        saveActionSlot();
    }

}

void MainWindow::mousePressEvent(QMouseEvent * ev) {
    //获取鼠标的坐标
    QPoint pt = ev->pos();
    qDebug() << pt << "\n";

    if (ev->button() == Qt::LeftButton) {
        qDebug() << "左键";
    }
    else if (ev->button() == Qt::RightButton) {
        qDebug() << "右键";
    }
    else if (ev->button() == Qt::MiddleButton) {
        qDebug() << "中键";
    }
}


//总结：
//1. 此次复习对文件数据的存储有了比之前更清晰的认知
//打开文件内容是要把磁盘上的文件内容计入到内存中的一个变量来，再从这个变量放到Qt的控件上
//写入文件是把Qt控件上的文件内容用一个变量保存起来，再用write()函数写入到文件中
//重写的函数名不能错注意
