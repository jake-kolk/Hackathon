#include "apicaller.h"
#include "apikeyconfigwindow.h"


ApiCaller::ApiCaller(QObject *parent, QString inputapiKey) : QObject(parent)

{
    apiKey = inputapiKey;
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
    QJsonObject{{"role", "system"}, {"content",
    "Your goal is to tell a good story that is 750 words "
    "long. divide the story into 5 pages. at the end of each page put a * character. If content is empty, make the story about something random"}},
    QJsonObject{{"role", "user"}, {"content", context}}
    };


    //json["max_tokens"] = 4000;

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

void ApiCaller::onReplyReceived(QNetworkReply *reply)
{
    qDebug("---------------------------------Response "
           "receved------------------------------------------");
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        //qDebug() << "Raw API Response:" << responseData;  // Log raw response


        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            QJsonArray choices = jsonObj["choices"].toArray();
            if (!choices.isEmpty()) {
                QString contextFormattedReply = "System: ";
                contextFormattedReply.append(
                    choices[0].toObject()["message"].toObject()["content"].toString());
                context.append(contextFormattedReply);
                qDebug() << contextFormattedReply;
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
        qDebug() << "HTTP Response Code:"
                 << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "Server Response:" << reply->readAll();
    }

    reply->deleteLater();
}

void ApiCaller::saveApiKey(QString apiKey) {
    // Create a JSON object to hold the key-value pair
    QJsonObject json;
    json["api_key"] = apiKey;

    // Create a JSON document from the JSON object
    QJsonDocument doc(json);

    // Open a file for writing
    QFile file("config.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open config.json for writing.";
        return;
    }

    // Write the JSON document to the file
    file.write(doc.toJson());
    file.close();
}
void ApiCaller::clearApiKey() {
    // Create a JSON object to hold the key-value pair
    QJsonObject json;
    json["api_key"] = "";

    // Create a JSON document from the JSON object
    QJsonDocument doc(json);

    // Open a file for writing
    QFile file("config.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open config.json for writing.";
        return;
    }

    // Write the JSON document to the file
    file.write(doc.toJson());
    file.close();
    this->apiKey = "";
}

QString ApiCaller::loadApiKey() {
    // Open the config file for reading
    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open config.json for reading.";
        return "";
    }
    qDebug() << "Loaded config.json";
    // Read the content of the file
    QByteArray data = file.readAll();
    file.close();

    // Parse the JSON data
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qWarning() << "Failed to parse config.json.";
        return "";
    }

    // Get the JSON object and extract the API key
    QJsonObject json = doc.object();
    this->apiKey = json["api_key"].toString();
    return json["api_key"].toString();
}

void ApiCaller::onApiKeyChanged(QString newApiKey)
{
    this->apiKey = newApiKey;
    saveApiKey(newApiKey);
}

void ApiCaller::onClearApiKeyButtonCLicked()
{
    this->clearApiKey();
}

bool ApiCaller::isApiKeyEmpty()
{
    if(this->apiKey == "") return true;
    else return false;
}
