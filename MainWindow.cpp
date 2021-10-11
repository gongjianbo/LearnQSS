#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PageBasic.h"
#include "PageOther.h"

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initOther();
    initPage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initOther()
{
    //菜单-其他
    QMenu *m_other = ui->menuOther;
    //m_other->setWindowFlag(Qt::NoDropShadowWindowHint); //去掉菜单阴影
    {
        QAction *a_disable = m_other->addAction("禁用");
        a_disable->setEnabled(false);
        m_other->addAction("可用");
        //图标位置有问题，而且默认样式下勾选框和图标会重合，
        //有icon后左侧增加一个宽度，整体会右移，要重新调整位置
        //m_other->addAction(QIcon("://img/logo.png"),"图标");
        //长文本自适应有问题
        //m_other->addAction("测试一下长文本内容选项");
        //对于复杂样式可以用QWidgetAction，任意组合
        //（也可以重写相关style）
        //但是QWidgetAction有个hover问题，详情百度
        QWidgetAction *wa = new QWidgetAction(m_other);
        QWidget *wrap = new QWidget;
        QHBoxLayout *hbox = new QHBoxLayout(wrap);
        QPushButton *hbtn = new QPushButton;
        hbtn->setIcon(QIcon("://img/logo.png"));
        QLabel *hlabel = new QLabel("QWidgetAction");
        hbox->addWidget(hbtn);
        hbox->addWidget(hlabel);
        wrap->setMouseTracking(true); //需要过滤得到move enter leave来切换，这里略
        wa->setDefaultWidget(wrap);
        m_other->addAction(wa);

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
        QAction *a_check1 = m_other->addAction("选项A");
        a_check1->setCheckable(true);
        a_check1->setChecked(true);
        QAction *a_check2 = m_other->addAction("选项B");
        a_check2->setCheckable(true);
        QAction *a_check3 = m_other->addAction("选项C");
        a_check3->setCheckable(true);
        /*QActionGroup *group = new QActionGroup(this);
        group->setExclusive(false);
        group->addAction(a_check1);
        group->addAction(a_check2);
        group->addAction(a_check3);*/
    }
    m_other->addSeparator();
    {
        //单选框
        QAction *a_check1 = m_other->addAction("选项A");
        a_check1->setCheckable(true);
        a_check1->setChecked(true);
        QAction *a_check2 = m_other->addAction("选项B");
        a_check2->setCheckable(true);
        QAction *a_check3 = m_other->addAction("选项C");
        a_check3->setCheckable(true);
        QActionGroup *group = new QActionGroup(this);
        group->setExclusive(true);
        group->addAction(a_check1);
        group->addAction(a_check2);
        group->addAction(a_check3);
    }
}

void MainWindow::initPage()
{
    //菜单-翻页
    QMenu *m_page = ui->menuPage;
    //m_page->setWindowFlag(Qt::NoDropShadowWindowHint); //去掉菜单阴影
    {
        //选择对应页面后，编辑框也要显示对应的样式表
        //（样式表编辑部分在后面做）
        int page_index = 0;
        ui->stackedWidget->addWidget(new PageBasic(this));
        m_page->addAction("基础部件",this,[this,page_index]{
            ui->stackedWidget->setCurrentIndex(page_index);
        });

        page_index++;
        ui->stackedWidget->addWidget(new PageOther(this));
        m_page->addAction("其他",this,[this,page_index]{
            ui->stackedWidget->setCurrentIndex(page_index);
        });
    }
}
