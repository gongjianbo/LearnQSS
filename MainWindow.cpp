#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMenu>
#include <QIcon>
#include <QAction>
#include <QActionGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenuBar()
{
    //菜单-翻页
    QMenu *m_page = ui->menuPage;
    //m_page->setWindowFlag(Qt::NoDropShadowWindowHint); //去掉菜单阴影
    {
        m_page->addAction("None");
    }

    //菜单-其他
    QMenu *m_other = ui->menuOther;
    //m_other->setWindowFlag(Qt::NoDropShadowWindowHint); //去掉菜单阴影
    {
        QAction *a_disable = new QAction("禁用",m_other);
        a_disable->setEnabled(false);
        m_other->addAction(a_disable);
        m_other->addAction("可用");
        //图标位置有问题，而且默认样式下勾选框和图标会重合，
        //有图标后左侧增加一个宽度，整体会右移，要重新调整位置
        //m_other->addAction(QIcon("://img/logo.png"),"图标");
        //长文本自适应有问题
        //m_other->addAction("测试一下长文本内容选项");
        QMenu *m_menu1 = new QMenu("子菜单A",m_other);
        m_other->addMenu(m_menu1);
        m_menu1->addAction("选项");
        m_menu1->addAction("选项");
        m_menu1->addAction("选项");
        QMenu *m_menu2 = new QMenu("子菜单B",m_other);
        m_other->addMenu(m_menu2);
        m_menu2->addAction("选项");
        m_menu2->addAction("选项");
        m_menu2->addAction("选项");
    }
    m_other->addSeparator();
    {
        //普通勾选框
        QAction *a_check1 = new QAction("选项A",m_other);
        a_check1->setCheckable(true);
        a_check1->setChecked(true);
        QAction *a_check2 = new QAction("选项B",m_other);
        a_check2->setCheckable(true);
        QAction *a_check3 = new QAction("选项C",m_other);
        a_check3->setCheckable(true);
        m_other->addAction(a_check1);
        m_other->addAction(a_check2);
        m_other->addAction(a_check3);
        /*QActionGroup *group = new QActionGroup(this);
        group->setExclusive(false);
        group->addAction(a_check1);
        group->addAction(a_check2);
        group->addAction(a_check3);*/
    }
    m_other->addSeparator();
    {
        //单选框
        QAction *a_check1 = new QAction("选项A",m_other);
        a_check1->setCheckable(true);
        a_check1->setChecked(true);
        QAction *a_check2 = new QAction("选项B",m_other);
        a_check2->setCheckable(true);
        QAction *a_check3 = new QAction("选项C",m_other);
        a_check3->setCheckable(true);
        m_other->addAction(a_check1);
        m_other->addAction(a_check2);
        m_other->addAction(a_check3);
        QActionGroup *group = new QActionGroup(this);
        group->setExclusive(true);
        group->addAction(a_check1);
        group->addAction(a_check2);
        group->addAction(a_check3);
    }
}
