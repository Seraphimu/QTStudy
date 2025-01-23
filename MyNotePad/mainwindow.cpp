#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //连接 点击新建按钮和newActionSlot()函数
    //QAction triggered 单击菜单栏的选项
    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);

    //绑定打开按钮和函数
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::openActionSlot);

    //绑定另存为按钮和函数
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::newActionSlot() {
    //清空文本框内容
    ui->textEdit->clear();
    //更改标题内容
    this->setWindowTitle("新建文本文档");
}

void MainWindow::openActionSlot() {
    //对话框，默认路径，文件格式
    //QString getOpenFileName(父类，标题，路径，类型（可省）);，返回文件的绝对路径
    //QCoreApplication::applicationFilePath()获取当前路径

    //实测，可以直接用 "./" 来打开
    QString fileName =  QFileDialog::getOpenFileName(this, "请选择一个文件", "./");
    // QString fileName =  QFileDialog::getOpenFileName(this, "请选择一个文件",
    //     QCoreApplication::applicationFilePath()
    // );
    // QString fileName =  QFileDialog::getOpenFileName(this, "请选择一个文件",
    //                                                 QCoreApplication::applicationFilePath(),"*.cpp"
    //                                                 );

    if (fileName.isEmpty()) {
        //warning(父类, 标题，内容);
        QMessageBox::warning(this, "警告", "请选择一个一个一个文件");
    }
    else {
        // qDebug() << fileName; //看看文件路径
        //显示内容："C:/Users/ATRI/MySpace/Projects/QTStudy/MyNotePad/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/debug/moc_mainwindow.cpp"

        //++++++重头戏+++++++++++++
        //下面是如何打开文件
        //1. 创建一个文件对象，并利用构造函数初始化
        QFile file(fileName);
        //2. 用open()函数指定打开方式
        file.open(QIODevice::ReadOnly);
        //3. 读取文件内容
        QByteArray ba = file.readAll();
        //4. 用setText()函数显示内容在TextEdit上
        //利用QString的构造函数转换数据类型
        ui->textEdit->setText(QString(ba));

        //5. 读完了记得关闭文件
        file.close();
    }
}

void MainWindow::saveActionSlot() {
    //打开文件
    QString fileName =  QFileDialog::getSaveFileName(this, "请选择一个文件", "./");
    if (fileName.isEmpty()) {
        //warning(父类, 标题，内容);
        QMessageBox::warning(this, "警告", "请选择一个一个一个文件");
    }
    else {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        //利用append()方法把ui->textEdit->toPlainText()拼接在ba后面，相当于类型置换为file.write()方法所需的参数类型

        QString content = ui->textEdit->toPlainText();

        //把QString转换为QBtyteArray类型的两种方法
        // QByteArray ba = content.toLatin1();
        QByteArray ba = content.toLocal8Bit();

        // qDebug() << ba;     //看看文件内容

        //无法把QString接在后面了，用上面两个函数转换也挺好的。
        // ba.append(content);

        file.write(ba);

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

    //button()函数可以获取按下的是什么按键
    if (ev->button() == Qt::LeftButton) {
        qDebug() << "按下的是左键。\n";
    }
    else if (ev->button() == Qt::RightButton) {
        qDebug() << "按下的是右键。\n";
    }
    else if (ev->button() == Qt::MiddleButton){
        qDebug() << "按下的是中键。\n";
    }
}




//总结：
//1. MainWindow
//2. 无右击转到槽
//3. 读写文件
//4. 跳出选择文件的窗口
//5. QString和QByteArray的相互转换
//6. 事件（快捷键）（信号）




