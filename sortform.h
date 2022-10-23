#ifndef SORTFORM_H
#define SORTFORM_H

#include <QWidget>
#include <dragwidget.h>

namespace Ui {
class SortForm;
}

class SortForm : public QWidget
{
    Q_OBJECT

public:
    explicit SortForm(QWidget *parent = nullptr);
    ~SortForm();

private slots:
    void on_close_game_btn_clicked();

private:
    Ui::SortForm *ui;
   // DragWidget *drag_w;
};

#endif // SORTFORM_H
