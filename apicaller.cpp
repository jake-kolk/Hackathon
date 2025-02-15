#include "apicaller.h"

ApiCaller::ApiCaller(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ApiCaller::onReplyReceived);
}

void ApiCaller::makeRequest(const QString &prompt)
{
    QUrl url("https://openrouter.ai/api/v1/chat/completions");


    QNetworkRequest request(url);

    // Set headers
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    // Create JSON payload
    QJsonObject json;
   json["model"] = "mistralai/mistral-7b-instruct:free";
    json["messages"] = QJsonArray{
        QJsonObject{{"role", "system"}, {"content", "You are a helpful assistant."}},
        QJsonObject{{"role", "user"}, {"content", prompt}}
    };
    json["max_tokens"] = 2000;

    // Convert JSON to QByteArray
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Send POST request
    manager.post(request, jsonData);
}

void ApiCaller::onReplyReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Raw API Response:" << responseData;  // Log raw response

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            QJsonArray choices = jsonObj["choices"].toArray();
            if (!choices.isEmpty()) {
                emit responseReceived(choices[0].toObject()["message"].toObject()["content"].toString());
            } else {
                qDebug() << "API response missing 'choices' field.";
            }
        } else {
            qDebug() << "API response is not a valid JSON object.";
        }
    } else {
        qDebug() << "API Error:" << reply->errorString();
        qDebug() << "HTTP Response Code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "Server Response:" << reply->readAll();
    }

    reply->deleteLater();
}


