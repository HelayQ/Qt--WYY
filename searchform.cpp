#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    this->setStyleSheet("QWidget{border:1px; background:white; border-radius:5px;}"
                        "QScrollBar:vertical{background:transparent; width:8px;}"
                        "QScrollBar::handle:vertical{background:rgb(224,224,224); width:5px; border-radius:3px;}"
                        "QScrollBar::up-arrow:vertical{border:none;}"
                        "QScrollBar::sub-line:vertical{background:transparent;}"
                        "QScrollBar::add-line:vertical{background:transparent;}"
                        );
    ui->label->setStyleSheet("QLabel#label{padding-left:15px;color:rgb(102,102,102);}");
    ui->listWidget->setStyleSheet("QListWidget{border:1px;background:blue;border-radius:5px;}"
                                  "QListWidget::Item{ background:white; height:60px;}"
                                  "QListWidget::Item:hover{background:rgb(246,246,247);}"
                                  );
}

SearchForm::~SearchForm()
{
    delete ui;
}
