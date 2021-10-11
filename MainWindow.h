#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//QSS学习Demo
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //菜单栏
    void initOther();
    //分页
    void initPage();

protected:
    //bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::MainWindow *ui;
};

