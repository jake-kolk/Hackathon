// apicaller.h
#ifndef APICALLER_H
#define APICALLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

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
    const QString apiKey = "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";
};

#endif // APICALLER_H

#define OPENROUTERKEY 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
