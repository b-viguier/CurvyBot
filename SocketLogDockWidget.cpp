#include "SocketLogDockWidget.h"
#include "ui_SocketLogDockWidget.h"
#include "CurvytronSocket.h"
#include "Events/AbstractEvent.h"
#include <QTime>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

SocketLogDockWidget::SocketLogDockWidget(CurvytronSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::SocketLogDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    connect(
        &_socket, &CurvytronSocket::eventIgnored,
        this, &SocketLogDockWidget::onEventIgnored
    );
    connect(
        &_socket, &CurvytronSocket::eventDispatched,
        this, &SocketLogDockWidget::onEventDispatched
    );
    connect(
        &_socket, &CurvytronSocket::eventSent,
        this, &SocketLogDockWidget::onEventSent
    );
}

SocketLogDockWidget::~SocketLogDockWidget()
{
    delete ui;
}

void SocketLogDockWidget::onEventDispatched(const AbstractEvent &event)
{
    logMessage(event.toString(), Qt::darkGreen);
}

void SocketLogDockWidget::onEventIgnored(const AbstractEvent &event)
{
    logMessage(event.toString(), Qt::darkRed);
}

void SocketLogDockWidget::onEventSent(const AbstractEvent &event)
{
    logMessage(event.toString(), Qt::darkBlue);
}

void SocketLogDockWidget::logMessage(const QString &text, const Qt::GlobalColor &color)
{
    auto item = new QListWidgetItem(
        QString("[%1] %2").arg(QTime::currentTime().toString()).arg(text)
    );
    item->setForeground(QBrush(color));
    ui->listWidget->insertItem(0, item);
}
