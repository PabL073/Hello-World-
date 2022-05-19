QT -= gui
QT += core
QT +=sql
QT += network


TARGET = test2
CONFIG += console
CONFIG += c++17 console
CONFIG -= app_bundle

TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bd_exception.cpp \
        document.cpp \
        document_access_recipe.cpp \
        document_add_favorite.cpp \
        document_add_nota.cpp \
        document_add_recipe.cpp \
        document_add_review.cpp \
        document_delete_favorite.cpp \
        document_delete_recipe.cpp \
        document_exception.cpp \
        document_favorite.cpp \
        document_favorites.cpp \
        document_list_recipes.cpp \
        document_log.cpp \
        document_passwordreset.cpp \
        document_register.cpp \
        document_send_name.cpp \
        document_send_photo.cpp \
        document_top_recipe.cpp \
        document_uniquemail.cpp \
        document_uniqueuser.cpp \
        exceptions.cpp \
        idocument_factory.cpp \
        iexceptions_factory.cpp \
        ingredient.cpp \
        logging.cpp \
        main.cpp \
        recipe.cpp \
        review.cpp \
        server.cpp \
        thread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bd_exception.h \
    document.h \
    document_access_recipe.h \
    document_add_favorite.h \
    document_add_nota.h \
    document_add_recipe.h \
    document_add_review.h \
    document_delete_favorite.h \
    document_delete_recipe.h \
    document_exception.h \
    document_favorite.h \
    document_favorites.h \
    document_list_recipes.h \
    document_log.h \
    document_passwordreset.h \
    document_register.h \
    document_send_name.h \
    document_send_photo.h \
    document_top_recipe.h \
    document_uniquemail.h \
    document_uniqueuser.h \
    exceptions.h \
    idocument.h \
    iexceptions.h \
    ingredient.h \
    logging.h \
    recipe.h \
    review.h \
    server.h \
    thread.h

DISTFILES += \
    log.txt
