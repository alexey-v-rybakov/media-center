#include <QCoreApplication>
#include "MediaCenterMainApp.h"


MediaCenterApp::MediaCenterApp(int &argc, char **argv)
               :QCoreApplication(argc, argv)
{
    m_rss_reader = new RSSReader(this);
    m_rss_reader->Start();
    return;
}



int main(int argc, char *argv[])
{
    MediaCenterApp app(argc, argv);

    return app.exec();
}

