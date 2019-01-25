#ifndef RSSREADER_H
#define RSSREADER_H

#include <QNetworkAccessManager>
#include <QTimer>

class RSSReader : public QObject
{
    Q_OBJECT
public:
    explicit RSSReader(QObject *parent = 0);


public:
    void Start();
    void Stop();

signals:
    void onReady();

private:
    void getData();

public slots:
        // Метод инициализации запроса на получение данных
    void onResult(QNetworkReply *reply);    // Слот обработки ответа о полученных данных
     void onUpdateTimer();

private:
    QNetworkAccessManager *m_manager; // менеджер сетевого доступа
    QTimer* m_update_timer;
};

#endif // RSSREADER_H
