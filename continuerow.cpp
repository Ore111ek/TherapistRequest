#include "continuerow.h"
#include "ui_continuerow.h"

QPixmap rotatePixMap(QString file){
    QPixmap m_pxOriginal = QPixmap(file);
    QPixmap rotatedPixmap(m_pxOriginal.size());
    QPainter* p = new QPainter(&rotatedPixmap);
    QSize size = m_pxOriginal.size();
    p->translate(size.height()/2,size.height()/2);
    p->rotate(90);
    p->translate(-size.height()/2,-size.height()/2);
    p->drawPixmap(0, 0, m_pxOriginal);
    p->end();
    delete p;
    return rotatedPixmap;
}

ContinueRow::ContinueRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContinueRow)
{
    ui->setupUi(this);

    drag_w = new DragWidget;
    this->layout()->addWidget(drag_w);

    /* Добавляем движимые картиночки */

    QLabel *boatIcon = new QLabel(drag_w);
    boatIcon->setPixmap(rotatePixMap(":/row/images/figure_1.png"));
    boatIcon->setMaximumSize(im_size,im_size);
    boatIcon->setScaledContents(true);
    boatIcon->move(10, 300);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carIcon = new QLabel(drag_w);
    carIcon->setPixmap(rotatePixMap(":/row/images/figure_1.png"));
    carIcon->setMaximumSize(im_size,im_size);
    carIcon->setScaledContents(true);
    carIcon->move(110, 110);
    carIcon->show();
    carIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon = new QLabel(drag_w);
    houseIcon->setPixmap(rotatePixMap(":/row/images/figure_3.png"));
    houseIcon->setMaximumSize(im_size,im_size);
    houseIcon->setScaledContents(true);
    houseIcon->move(110, 220);
    houseIcon->show();
    houseIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *hIcon = new QLabel(drag_w);
    hIcon->setPixmap(rotatePixMap(":/row/images/figure_3.png"));
    hIcon->setMaximumSize(im_size,im_size);
    hIcon->setScaledContents(true);
    hIcon->move(10, 70);
    hIcon->show();
    hIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *hoIcon = new QLabel(drag_w);
    hoIcon->setPixmap(rotatePixMap(":/row/images/figure_1.png"));
    hoIcon->setMaximumSize(im_size,im_size);
    hoIcon->setScaledContents(true);
    hoIcon->move(110, 330);
    hoIcon->show();
    hoIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *bIcon = new QLabel(drag_w);
    bIcon->setPixmap(rotatePixMap(":/row/images/figure_3.png"));
    bIcon->setMaximumSize(im_size,im_size);
    bIcon->setScaledContents(true);
    bIcon->move(10, 190);
    bIcon->show();
    bIcon->setAttribute(Qt::WA_DeleteOnClose);

    /* Добавили движимые картиночки */




    /* Добавляем недвижимые картиночки */
    task = new QWidget(this);
    task->setWindowFlag(Qt::WindowStaysOnTopHint);

    screen = QApplication::screens().at(0);
    int screen_w = screen->size().width();
    int screen_h = screen->size().height();
    int step = 5; //(screen_w-im_size*im_in_row)/(im_in_row+1);
    task->setGeometry(screen_w-im_size-30,60, im_size,im_size*(im_in_row-1)+step*(im_in_row-1));//10,50


    task_images[0] = new QLabel(task);
    task_images[0]->setPixmap(rotatePixMap(":/row/images/figure_1.png"));
    task_images[0]->setMaximumSize(im_size,im_size);
    task_images[0]->setScaledContents(true);
    task_images[0]->move(0,step);//move(step, 0);
    task_images[0]->show();
    task_images[0]->setAttribute(Qt::WA_DeleteOnClose);

    task_images[1] = new QLabel(task);
    task_images[1]->setPixmap(rotatePixMap(":/row/images/figure_3.png"));
    task_images[1]->setMaximumSize(im_size,im_size);
    task_images[1]->setScaledContents(true);
    task_images[1]->move(0, step*2 + im_size);//move(step*2 + im_size, 0);
    task_images[1]->show();
    task_images[1]->setAttribute(Qt::WA_DeleteOnClose);

    task->show();
    /* Добавили недвижимые картиночки */


    // Разделительная черта
    line_sep = new QFrame(this);
    line_sep->setFrameShape(QFrame::VLine);
    line_sep->setFrameShadow(QFrame::Sunken);
    line_sep->setWindowFlag(Qt::WindowStaysOnTopHint);
    line_sep->setGeometry(screen_w-im_size-50,50, 5,screen_h-90);//10,50 + im_size + 5,screen_w-20,5
    line_sep->show();


/*    line_widget = new QWidget(this);
    line_widget->setWindowFlag(Qt::WindowStaysOnTopHint);

    line_sep = new QFrame(line_widget);
    line_sep->setFrameShape(QFrame::HLine);
    line_sep->setFrameShadow(QFrame::Sunken);

    line_widget->setGeometry(10,screen_h/3,screen_w-20,5);//10,50
    line_sep->show();
    line_widget->show();
    */

}

ContinueRow::~ContinueRow()
{
    delete ui;
}

void ContinueRow::on_close_game_btn_clicked()
{
    this->close();
}

