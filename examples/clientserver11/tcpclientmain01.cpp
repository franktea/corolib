/**
 * @file
 * @brief
 *
 * @author Johan Vanslembrouck (johan.vanslembrouck@altran.com, johan.vanslembrouck@gmail.com)
 */

#include <QCoreApplication>
#include <QLoggingCategory>

#include "tcpconfigfile.h"
#include "tcpclient01.h"

const int corolib::priority = 0x01;

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QT_USE_NAMESPACE

    QCoreApplication app(argc, argv);

    // When launched automatically at boot time, the full path of the .cfg file is needed"
    const QString configFileName = "tcpclient01.cfg";

    TcpConfigFile configFile;

    if (!configFile.readConfigurationFile(configFileName))
        // If not, the default settings will be used.
        qInfo() << "Could not open configuration file - using default settings";

    if (!configuration.m_displayInfoMessages)
        QLoggingCategory::setFilterRules(QStringLiteral("*.info=false"));

    TcpClient01 tcpClient01(0, USE_CRC);
    tcpClient01.start();

    return app.exec();
}