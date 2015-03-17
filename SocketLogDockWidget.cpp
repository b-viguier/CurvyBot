#include "SocketLogDockWidget.h"
#include "ui_SocketLogDockWidget.h"
#include "CurvytronSocket.h"
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
        &_socket, &CurvytronSocket::messageReceived,
        this, &SocketLogDockWidget::onMessageReceived
    );
}

SocketLogDockWidget::~SocketLogDockWidget()
{
    delete ui;
}

void SocketLogDockWidget::onMessageReceived(const QString &type, const QJsonValue& data)
{
    QJsonDocument json;
    switch(data.type()) {
        case QJsonValue::Array:
            json = QJsonDocument(data.toArray());
            break;
        case QJsonValue::Object:
            json = QJsonDocument(data.toObject());
            break;
        default:
            json = QJsonDocument(QJsonArray{data});
    }

    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QTime::currentTime().toString()));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(type));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString(json.toJson(QJsonDocument::Compact))));
}
