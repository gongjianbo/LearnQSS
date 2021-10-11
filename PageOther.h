#ifndef PAGEOTHER_H
#define PAGEOTHER_H

#include <QWidget>

namespace Ui {
class PageOther;
}

class PageOther : public QWidget
{
    Q_OBJECT

public:
    explicit PageOther(QWidget *parent = nullptr);
    ~PageOther();

private:
    Ui::PageOther *ui;
};

#endif // PAGEOTHER_H
