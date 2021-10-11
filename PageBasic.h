#ifndef PAGEBASIC_H
#define PAGEBASIC_H

#include <QWidget>

namespace Ui {
class PageBasic;
}

class PageBasic : public QWidget
{
    Q_OBJECT

public:
    explicit PageBasic(QWidget *parent = nullptr);
    ~PageBasic();

private:
    Ui::PageBasic *ui;
};

#endif // PAGEBASIC_H
