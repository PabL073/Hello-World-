#ifndef LOGGING_H
#define LOGGING_H
#include <QString>

class Logging
{
private:
    static Logging* m_pInstance;
    QString _message;

public:
    static void	destroyInstance();
    static Logging& getInstance(QString message);
    static void logging();

private:
    Logging(QString message):_message(message) {};
    ~Logging() {};
};

#endif // LOGGING_H
