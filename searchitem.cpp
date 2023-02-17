#include "searchitem.h"
#include "ui_searchitem.h"

SearchItem::SearchItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchItem)
{
    ui->setupUi(this);
}

SearchItem::~SearchItem()
{
    delete ui;
}
