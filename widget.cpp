#include "widget.h"
#include "ui_widget.h"
#include "duthread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mThread1 = new DuThread(10,this);
    mThread2 = new DuThread(20,this);
    mThread2 = new DuThread(30,this);

    ui->progressBar->setValue(0);
    ui->dial->setValue(0);
    ui->lcdNumber->display(0);

    connect(mThread1,&DuThread::valorCambiado,ui->progressBar,&QProgressBar::setValue);
    connect(mThread2,&DuThread::valorCambiado,ui->dial,&QDial::setValue);
    //connect(mThread3,SIGNAL(valorCambiado(int)),ui->lcdNumber,SLOT(display(int)));
    connect(mThread3, &DuThread::valorCambiado,ui->lcdNumber,
            static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciarButton_clicked()
{
    mThread1->start();
    mThread2->start();
    mThread3->start();
}

void Widget::on_detenerButton_clicked()
{
    mThread1->terminate();
    mThread2->terminate();
    mThread3->terminate();
}
