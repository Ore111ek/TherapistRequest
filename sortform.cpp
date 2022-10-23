#include "sortform.h"
#include "ui_sortform.h"

SortForm::SortForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortForm)
{
    ui->setupUi(this);


    /* Добавляем движимые картиночки */
    QLabel *boatIcon = new QLabel(ui->drag_w_com);
    boatIcon->setPixmap(QPixmap(":/row/images/figure_1.png"));
    boatIcon->setMaximumSize(im_size,im_size);
    boatIcon->setScaledContents(true);
    boatIcon->move(10, 20);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carIcon = new QLabel(ui->drag_w_com);
    carIcon->setPixmap(QPixmap(":/row/images/figure_2.png"));
    carIcon->setMaximumSize(im_size,im_size);
    carIcon->setScaledContents(true);
    carIcon->move(130, 160);
    carIcon->show();
    carIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon = new QLabel(ui->drag_w_com);
    houseIcon->setPixmap(QPixmap(":/row/images/figure_3.png"));
    houseIcon->setMaximumSize(im_size,im_size);
    houseIcon->setScaledContents(true);
    houseIcon->move(220, 30);
    houseIcon->show();
    houseIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *hIcon = new QLabel(ui->drag_w_com);
    hIcon->setPixmap(QPixmap(":/row/images/food_1.png"));
    hIcon->setMaximumSize(im_size,im_size);
    hIcon->setScaledContents(true);
    hIcon->move(20, 130);
    hIcon->show();
    hIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *hoIcon = new QLabel(ui->drag_w_com);
    hoIcon->setPixmap(QPixmap(":/row/images/food_2.png"));
    hoIcon->setMaximumSize(im_size,im_size);
    hoIcon->setScaledContents(true);
    hoIcon->move(120, 10);
    hoIcon->show();
    hoIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *bIcon = new QLabel(ui->drag_w_com);
    bIcon->setPixmap(QPixmap(":/row/images/food_3.png"));
    bIcon->setMaximumSize(im_size,im_size);
    bIcon->setScaledContents(true);
    bIcon->move(230, 140);
    bIcon->show();
    bIcon->setAttribute(Qt::WA_DeleteOnClose);

    /* Добавили движимые картиночки */



}

SortForm::~SortForm()
{
    delete ui;
}

void SortForm::on_close_game_btn_clicked()
{
    this->close();
}

