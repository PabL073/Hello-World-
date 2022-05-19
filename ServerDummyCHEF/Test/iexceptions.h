#ifndef IEXCEPTIONS_H
#define IEXCEPTIONS_H
#include <QDebug>

class IExceptions
{
public:
    IExceptions() {};
    virtual QString Message()=0;

private:

};

class Factory_Exceptions
{
public:
     static IExceptions* Create_BD_Exception_Instance();
     static IExceptions* Create_Protocol_Exception_Instance();
};

#endif // IEXCEPTIONS_H
