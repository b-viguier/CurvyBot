#ifndef SOCKETLOGDOCKWIDGET_H
#define SOCKETLOGDOCKWIDGET_H

#include <QDockWidget>

class CurvytronSocket;
class QJsonArray;
class AbstractEvent;

namespace Ui {
class SocketLogDockWidget;
}

class SocketLogDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit SocketLogDockWidget(CurvytronSocket& socket, QWidget *parent = 0);
    ~SocketLogDockWidget();

private slots:
    void onEventReceived(const AbstractEvent&);

private:
    Ui::SocketLogDockWidget *ui;
    CurvytronSocket& _socket;
};

#endif // SOCKETLOGDOCKWIDGET_H
