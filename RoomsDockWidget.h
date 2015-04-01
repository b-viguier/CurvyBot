#ifndef ROOMSDOCKWIDGET_H
#define ROOMSDOCKWIDGET_H

#include <QDockWidget>

class QJsonValue;
class CurvytronSocket;
#include <Events/RoomOpenEvent.h>
#include <Events/RoomPlayersEvent.h>
#include <Events/RoomCloseEvent.h>

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
    void onSocketConnected();

    void on_roomsList_currentIndexChanged(int);
    void on_createButton_clicked();

private:
    void onRoomOpen(const RoomOpenEvent& event);
    void onRoomPlayers(const RoomPlayersEvent& event);
    void onRoomClose(const RoomCloseEvent& event);

    Ui::RoomsDockWidget *ui;
    CurvytronSocket& _socket;
};

#endif // ROOMSDOCKWIDGET_H
