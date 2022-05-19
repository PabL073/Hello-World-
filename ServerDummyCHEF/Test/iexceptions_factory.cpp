#include "iexceptions_factory.h"
#include "bd_exception.h"
#include "document_exception.h"

IExceptions* Factory_Exceptions::Create_BD_Exception_Instance()
{
    return new BD_exception();
};

IExceptions* Factory_Exceptions::Create_Protocol_Exception_Instance()
{
    return new Protocol_Exception();
}
