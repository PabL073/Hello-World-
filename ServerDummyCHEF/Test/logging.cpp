#include "logging.h"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <ctime>

Logging* Logging::m_pInstance = nullptr;

void Logging::destroyInstance()
{
    if (m_pInstance == nullptr)
        return;

    delete m_pInstance;
    m_pInstance = nullptr;
};

Logging& Logging::getInstance(QString message)
{
    if (m_pInstance == nullptr)
        m_pInstance = new Logging(message);
    else
        m_pInstance->_message=message;

    return *m_pInstance;
}

void Logging::logging()
{
      std::ofstream myfile;
      myfile.open ("C:\\Users\\caran\\OneDrive\\Desktop\\Test\\log.txt",std::ios::app);
      time_t now=time(0);
      char* date_time=ctime(&now);
      myfile<<date_time;
      myfile <<m_pInstance->_message.toStdString().c_str()<<std::endl;
      myfile.close();
};
