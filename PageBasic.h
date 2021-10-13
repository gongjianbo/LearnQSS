#pragma once
#include <QWidget>

namespace Ui {
class PageBasic;
}

//基础组件
class PageBasic : public QWidget
{
    Q_OBJECT
public:
    explicit PageBasic(QWidget *parent = nullptr);
    ~PageBasic();

    //QPushButton
    void initButton();

private:
    Ui::PageBasic *ui;
};

