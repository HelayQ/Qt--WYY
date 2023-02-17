#ifndef SEARCHITEM_H
#define SEARCHITEM_H

#include <QWidget>

namespace Ui {
class SearchItem;
}

class SearchItem : public QWidget
{
    Q_OBJECT

public:
    explicit SearchItem(QWidget *parent = 0);
    ~SearchItem();

private:
    Ui::SearchItem *ui;
};

#endif // SEARCHITEM_H
