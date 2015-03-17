#ifndef SOCKETLOGDOCKWIDGET_H
#define SOCKETLOGDOCKWIDGET_H

#include <QDockWidget>

class CurvytronSocket;
class QJsonArray;

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
    void onMessageReceived(const QString&, const QJsonValue&);

private:
    Ui::SocketLogDockWidget *ui;
    CurvytronSocket& _socket;
};

#endif // SOCKETLOGDOCKWIDGET_H
