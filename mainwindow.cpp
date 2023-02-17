#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //去除窗口默认的边框
    this->setWindowFlag(Qt::FramelessWindowHint);
    //加入过滤器
    ui->line_Search->installEventFilter(this);
    ui->line_Search->setMouseTracking(false);
    searchForm = new SearchForm(this); //创建一个新的搜索框
    searchForm->installEventFilter(this);
    searchForm->setMouseTracking(false);
    searchForm->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_max_clicked()
{
    if(this->isMaximized())
        this->showNormal(); //默认大小
    else
        this->showMaximized();  //最大化
}

void MainWindow::on_pushButton_min_clicked()
{
    this->showMinimized(); //最小化
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //获取title widget 的高度，这里固定为60px
    int titleHeight = ui->title_Widget->height();
    if(event->y() <titleHeight)
    {
        last = event->globalPos(); //获取到按压的位置
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int titleHeight = ui->title_Widget->height();
    if(event->y() <titleHeight)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        this->move(this->x()+dx,this->y()+dy);
    }

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //当点击查询按钮
    if(watched == ui->line_Search)
    {

        if(event->type() == QEvent::MouseButtonPress)
        {
            int x = ui->line_Search->x();
            int y = ui->line_Search->y();
            int hight = ui->line_Search->height();
            searchForm->setGeometry(x-45,y+hight+2,searchForm->width(),searchForm->height());
            searchForm->show();
            return true;
        }
        else {
            return false;
        }

    }
    else if (watched == searchForm)
    {
        //当鼠标离开时候，界面隐藏
        if(event->type() == QEvent::Leave)
        {
            searchForm->hide();
            return true;
        }
        else {
            return false;
        }

    }
    return QWidget::eventFilter(watched,event);
}
