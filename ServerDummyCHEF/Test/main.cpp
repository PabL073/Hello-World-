#include <QCoreApplication>
#include <QTcpServer>
#include <QThread>
#include<iostream>
#include <QtSql>
#include <QSqlError>
#include "server.h"
#include"idocument.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server myServer;
    myServer.StartServer();

    return a.exec();
}
