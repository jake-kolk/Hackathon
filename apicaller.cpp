
#include "apicaller.h"

ApiCaller::ApiCaller(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ApiCaller::onReplyReceived);
}

void ApiCaller::makeRequest(const QString &prompt)
{

    // Define API URL
    QUrl url("https://openrouter.ai/api/v1/chat/completions");
    QNetworkRequest request(url);

    // Set headers
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Set Authorization header correctly
    QByteArray authHeader = "Bearer " + apiKey.toUtf8();
    request.setRawHeader("Authorization", authHeader);

    // Create JSON payload
    QJsonObject json;


    QString formattedPrompt = " User: ";
    formattedPrompt.append(prompt);
    formattedPrompt.append(" ");
    context.append(formattedPrompt);
    json["model"] = "mistralai/mistral-7b-instruct:free";
    json["messages"] = QJsonArray{
    QJsonObject{{"role", "system"}, {"content", "You are a helpful assistant."}},
    QJsonObject{{"role", "user"}, {"content", context}}
    };

    json["max_tokens"] = 4000;

    // Convert JSON to QByteArray
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Debugging output
    qDebug() << "Sending request to:" << url.toString();
    //qDebug() << "Authorization Header:" << request.rawHeader("Authorization");
    //qDebug() << "JSON Payload:" << jsonDoc.toJson(QJsonDocument::Indented);

    // Send POST request
    QNetworkReply *reply = manager.post(request, jsonData);

}

void ApiCaller::onReplyReceived(QNetworkReply *reply) {
    qDebug("---------------------------------Response receved------------------------------------------");
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Raw API Response:" << responseData;  // Log raw response

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            QJsonArray choices = jsonObj["choices"].toArray();
            if (!choices.isEmpty()) {
                QString contextFormattedReply = "System: ";
                contextFormattedReply.append(choices[0].toObject()["message"].toObject()["content"].toString());
                context.append(contextFormattedReply);
                qDebug("-------------------------ResponseRecevedEmitted----------------");
                emit responseReceived(contextFormattedReply);
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

