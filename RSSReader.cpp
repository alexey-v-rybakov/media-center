#include "RSSReader.h"
#include "stdio.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>

RSSReader::RSSReader(QObject *parent) : QObject(parent)
{

    m_update_timer = new QTimer();
    connect(m_update_timer, SIGNAL(timeout()), this, SLOT(onUpdateTimer()));

    // Инициализируем менеджер ...
    m_manager = new QNetworkAccessManager(this);
    // ... и подключаем сигнал о завершении получения данных к обработчику полученного ответа
    connect(m_manager, &QNetworkAccessManager::finished, this, &RSSReader::onResult);

}

void RSSReader::Start()
{
    getData();
    m_update_timer->start(5000);

}

void RSSReader::getData()
{
    QUrl url("https://lenta.ru/rss"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    m_manager->get(request);      // Выполняем запрос
    return;

}

void RSSReader::onUpdateTimer()
{
    printf("on timer\n");
    getData();

}

void RSSReader::onResult(QNetworkReply *reply)
{
    // Если в процесе получения данных произошла ошибка
    if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
        qDebug() << "ERROR";
        qDebug() << reply->errorString();
    } else {
        // В противном случае создаём объект для работы с файлом
        QFile *file = new QFile("file2.xml");
        // Создаём файл или открываем его на перезапись ...
        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
            file->close();                  // закрываем файл
        qDebug() << "Downloading is completed";

        }
    }
}

