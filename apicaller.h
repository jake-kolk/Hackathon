// apicaller.h
#ifndef APICALLER_H
#define APICALLER_H

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

class ApiCaller : public QObject
{
    Q_OBJECT
public:
    explicit ApiCaller(QObject *parent = nullptr);
    void makeRequest(const QString &prompt);
    QString getResponse() const;

signals:
    void responseReceived(QString response);

private slots:
    void onReplyReceived(QNetworkReply *reply);

private:
    QNetworkAccessManager manager;
    const QString apiKey
        = "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";
    QString context;
};
//new key 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
#endif // APICALLER_H
