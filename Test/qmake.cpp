#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//水平布局
#include <QHBoxLayout>
//垂直布局
#include <QVBoxLayout>
//窗口
#include <QWidget>

int main(int argc, char * argv[]) {
    QApplication app(argc, argv);

    //信息控件
    QLabel * infoLabel = new QLabel();
    //打开控件
    QLabel * openLabel = new QLabel();

    //文本行编辑框
    QLineEdit * cmdLineEdit = new QLineEdit();
    //输入按钮
    QPushButton * commitButton = new QPushButton();
    //取消按钮
    QPushButton * cancelButton = new QPushButton();
    //浏览按钮
    QPushButton * browseButton = new QPushButton();

    infoLabel->setText("Input: Cmd");
    openLabel->setText("open");
    commitButton->setText("commit");
    cancelButton->setText("cancel");
    browseButton->setText("browse");

    QHBoxLayout * cmdLayout = new QHBoxLayout();
    //把打开提示和输入输入框水平对齐
    cmdLayout->addWidget(openLabel);
    cmdLayout->addWidget(cmdLineEdit);

    //把打开、取消、浏览水平对齐
    QHBoxLayout * buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(commitButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(browseButton);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget(infoLabel);

    mainLayout->addLayout(cmdLayout);
    mainLayout->addLayout(buttonLayout);

    QWidget w;
    w.setLayout(mainLayout);
    w.show();



    return app.exec();
}

//1. qmake -project
//2. 修改.pro文件 QT += widgets gui
//3. qmake
//4. mingw32-make