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
#include <QFile>
#include <cstdlib>
#include <windows.h>


class ApiCaller : public QObject
{
    Q_OBJECT
public:
    explicit ApiCaller(QObject *parent = nullptr, QString apikey = "");
    void makeRequest(const QString &prompt);
    QString getResponse() const;
    QString loadApiKey();
    void clearApiKey();
public slots:
     void onApiKeyChanged(QString newApiKey);
signals:
    void responseReceived(QString response);

private slots:
    void onReplyReceived(QNetworkReply *reply);


private:
    QNetworkAccessManager manager;
    QString context;
    QString apiKey;
    void saveApiKey(QString apiKey);

};
//new key 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
#endif // APICALLER_H
