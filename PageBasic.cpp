#include "PageBasic.h"
#include "ui_PageBasic.h"

PageBasic::PageBasic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageBasic)
{
    ui->setupUi(this);
}

PageBasic::~PageBasic()
{
    delete ui;
}
