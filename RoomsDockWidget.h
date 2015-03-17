#ifndef ROOMSDOCKWIDGET_H
#define ROOMSDOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
class RoomsDockWidget;
}

class RoomsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit RoomsDockWidget(QWidget *parent = 0);
    ~RoomsDockWidget();

private:
    Ui::RoomsDockWidget *ui;
};

#endif // ROOMSDOCKWIDGET_H
