#ifndef CURVYTRONSOCKET_H
#define CURVYTRONSOCKET_H

#include <QObject>
#include <QJsonValue>
class QString;
class QWebSocket;

class CurvytronSocket : public QObject
{
    Q_OBJECT
public:
    explicit CurvytronSocket(QWebSocket& socket);
    ~CurvytronSocket();

    QWebSocket &socket() const;

signals:
    void messageReceived(const QString& type, const QJsonValue& data);

public slots:
    void sendMessage(const QString& type, const QJsonValue& data = QJsonValue());

private slots:
    void onSocketMessageReceived(const QString&);

private:
    QWebSocket& _socket;
};

#endif // CURVYTRONSOCKET_H
