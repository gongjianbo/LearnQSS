#include "PageBasic.h"
#include "ui_PageBasic.h"
#include <QButtonGroup>
#include <QMenu>
#include <QAction>

PageBasic::PageBasic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageBasic)
{
    ui->setupUi(this);
    initButton();
}

PageBasic::~PageBasic()
{
    delete ui;
}

void PageBasic::initButton()
{
    //第一组按钮
    QMenu *menu1 = new QMenu(this);
    menu1->addAction("选项");
    menu1->addAction("选项");
    menu1->addAction("选项");
    ui->btnA1->setMenu(menu1); //设置按钮菜单

    //第二组按钮
    QButtonGroup *group2 = new QButtonGroup(this);
    group2->setExclusive(true); //单个选中
    group2->addButton(ui->btnA2);
    group2->addButton(ui->btnB2);
    group2->addButton(ui->btnC2);
    group2->addButton(ui->btnD2);
    ui->btnA2->setChecked(true);

    //第三组按钮
    QButtonGroup *group3 = new QButtonGroup(this);
    group3->setExclusive(false); //多个选中
    group3->addButton(ui->btnA3);
    group3->addButton(ui->btnB3);
    ui->btnA3->setChecked(true);
    ui->btnB3->setChecked(true);
    //C3选中了但不可点击
    //D3未选中且不可点击
}
