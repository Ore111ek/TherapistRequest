#ifndef CONTINUEROW_H
#define CONTINUEROW_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QScreen>
#include <QPainter>
#include <dragwidget.h>

#define task_im_num 2
#define im_size 90
#define im_in_row 3

namespace Ui {
class ContinueRow;
}

class ContinueRow : public QWidget
{
    Q_OBJECT

public:
    explicit ContinueRow(QWidget *parent = nullptr);
    ~ContinueRow();

private slots:
    void on_close_game_btn_clicked();

private:
    Ui::ContinueRow *ui;
    DragWidget *drag_w = nullptr;
    QLabel *task_images[task_im_num];
    QWidget *task = nullptr;
    QWidget *line_widget = nullptr;
    QFrame *line_sep = nullptr;
    QScreen *screen;
};

#endif // CONTINUEROW_H
