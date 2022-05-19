#include "thread.h"
#include "idocument.h"
#include "iexceptions.h"

Thread::Thread(qintptr ID,QObject *parent)
    : QThread{parent}
{
    this->socketDescriptor=ID;
}

void Thread::run()
{


       qDebug() <<socketDescriptor<< " Thread started";

       socket = new QTcpSocket();

       // set the ID
       if(!socket->setSocketDescriptor(this->socketDescriptor))
       {
           // something's wrong, we just emit a signal
           emit error(socket->error());
           return;
       }

       // connect socket and signal
       // note - Qt::DirectConnection is used because it's multithreaded
       //        This makes the slot to be invoked immediately, when the signal is emitted.

       connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
       connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);


       // We'll have multiple clients, we want to know which is whichc
       qDebug() << socketDescriptor << " Client connected";

       // make this thread a loop,
       // thread will stay alive so that signal/slot to function properly
       // not dropped out in the middle when thread dies

       exec();
}

void Thread::readyRead()
{
    QByteArray Data = socket->readAll();

    qDebug() << socketDescriptor<< "Data in: " << Data;

    QString str=QString(Data);
    int nr=str.count('/');
    int prot=str.section("/",0,0).toInt();
    IDocument *pdocument;
    QString send;
    QString delim="/";

    switch(prot)
    {
    case(LOGARE):
    {
        if(nr==3)
        {
        pdocument = Factory_Document::Create_LogInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
       }
        break;
    }
    case(VERIF_USER_UNIC):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_UniqueUserInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(VERIF_MAIL_UNIC):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_UniqueMailInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(REGISTER):
    {
        if(nr==8)
        {
        QString lastname=str.section(delim,1,1);
        QString firstname=str.section(delim,2,2);
        QString email=str.section(delim,4,4);
        QString username=str.section(delim,3,3);
        QString password=str.section(delim,5,5);
        QString account=str.section(delim,6,6);
        QString answer=str.section(delim,7,7);
        pdocument = Factory_Document::Create_RegisterInstance(lastname,firstname,email,username,password,account,answer);
        send=pdocument->Message();
        }
            else
            {
                try
                {
                    IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                    throw ex;
                }
                catch(IExceptions *ex)
                {
                    send.append(ex->Message());
                }
            }
        break;
    }
    case(PASSWORD_RESET):
    {
        if(nr==4)
        {
        pdocument = Factory_Document::Create_PasswordResetInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(LISTA_DENUMIRI_RETETE):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_ListRecipesInstance(str,0,1);
        send=pdocument->Message();
        }
            else
            {
                try
                {
                    IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                    throw ex;
                }
                catch(IExceptions *ex)
                {
                    send.append(ex->Message());
                }
            }
        break;
    }
    case(LISTA_RETETE_CHEFI):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_ListRecipesInstance(str,1,0);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(ACCESS_RECIPE):
    {
        if(nr==3)
        {
        pdocument = Factory_Document::Create_AccessRecipeInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(ADD_REVIEW):
    {
        if(nr==5)
        {
        pdocument = Factory_Document::Create_AddReviewInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(ADD_NOTA):
    {
        if(nr==4)
        {
        pdocument = Factory_Document::Create_AddNotaInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(DELETE_RECIPE):
    {
        if(nr==3)
        {
        pdocument = Factory_Document::Create_DeleteRecipeInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(FAVORITES_LIST):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_FavoritesInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(ADD_FAVORITE):
    {
        if(nr==4)
        {
        pdocument = Factory_Document::Create_AddFavoriteInstance(str);
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(DELETE_FAVORITE):
    {
    if(nr==4)
    {
    pdocument = Factory_Document::Create_DeleteFavoriteInstance(str);
    send=pdocument->Message();
    }
    else
    {
        try
        {
            IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
            throw ex;
        }
        catch(IExceptions *ex)
        {
            send.append(ex->Message());
        }
    }
    break;
    }
    case(ADD_RECIPE):
    {
        pdocument = Factory_Document::Create_AddRecipeInstance(str);
        send=pdocument->Message();
        break;
    }
    case(TOP):
    {
        if(nr==1)
        {
        pdocument = Factory_Document::Create_TopRecipeInstance();
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(SEND_NAME):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_SendNameInstance(str.section('/',1,1));
        send=pdocument->Message();
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        };
        break;
    }
    case(RETETE_CONT_CHEF):
    {
        if(nr==2)
        {
        pdocument = Factory_Document::Create_SendNameInstance(str.section('/',1,1));
        send=pdocument->Message();
        pdocument=Factory_Document::Create_ListRecipesInstance(send,1,0);
        send=pdocument->Message();
        send.erase(send.begin(),send.begin()+1);
        str="17";
        str+=send;
        send=str;
        }
        else
        {
            try
            {
                IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
                throw ex;
            }
            catch(IExceptions *ex)
            {
                send.append(ex->Message());
            }
        }
        break;
    }
    case(SEND_PHOTO):
    {
    pdocument = Factory_Document::Create_SendPhotoInstance(str);
    send=pdocument->Message();
    break;
    }
    default:
    {
        try
        {
           IExceptions* ex=Factory_Exceptions::Create_Protocol_Exception_Instance();
           throw ex;
        }
        catch(IExceptions *ex)
        {
            send.append(ex->Message());
        }
        break;
    }
    }
    qDebug()<<"Data out:"<<send;
    print(send);

    //socket->close();
};

void Thread::print(QString send)
{
    QByteArray mesaj;
    mesaj=send.toUtf8();
    socket->write(mesaj);
    //socket->flush();
    //socket->waitForBytesWritten(100);
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor<< "Disconnected: ";

    socket->deleteLater();
    exit(0);

}
