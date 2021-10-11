#include "PageOther.h"
#include "ui_PageOther.h"

PageOther::PageOther(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOther)
{
    ui->setupUi(this);
}

PageOther::~PageOther()
{
    delete ui;
}
