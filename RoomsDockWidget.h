#ifndef ROOMSDOCKWIDGET_H
#define ROOMSDOCKWIDGET_H

#include <QDockWidget>

class QJsonValue;
class CurvytronSocket;
class RoomOpenEvent;

namespace Ui {
class RoomsDockWidget;
}

class RoomsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit RoomsDockWidget(CurvytronSocket& socket, QWidget *parent = 0);
    ~RoomsDockWidget();

private slots:
    void onRoomOpen(const RoomOpenEvent& event);
    void onSocketConnected();

private:
    Ui::RoomsDockWidget *ui;
    CurvytronSocket& _socket;
};

#endif // ROOMSDOCKWIDGET_H
