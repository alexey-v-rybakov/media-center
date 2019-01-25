#ifndef MEDIACENTERMAINAPP
#define MEDIACENTERMAINAPP

#include "RSSReader.h"
#include <QCoreApplication>



class MediaCenterApp : public QCoreApplication
{
    Q_OBJECT

    public:
        MediaCenterApp(int &argc, char **argv);
        ~MediaCenterApp() {};


    private:
        RSSReader* m_rss_reader;

};

#endif // MEDIACENTERMAINAPP

