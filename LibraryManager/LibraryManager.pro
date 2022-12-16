QT       += core gui sql#加入数据库模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    bookclassifymanager.h \
    bookinformationmanager.h \
    bookinformationmanageradddatadialog.h \
    bookinformationmanagermodifydialog.h \
    booksearch.h \
    borrow_history.h \
    borrow_info.h \
    login.h \
    dboperator.h \
    mainwindow.h \
    managermainwindow.h \
    signup.h \
    splashscreen.h \
    userprofilemanager.h\
    readermanager.h\
    readerinformationmanageradddatadialog.h\
    readerinformationmanagermodifydialog.h\

SOURCES += \
    bookclassifymanager.cpp \
    bookinformationmanager.cpp \
    bookinformationmanageradddatadialog.cpp \
    bookinformationmanagermodifydialog.cpp \
    booksearch.cpp \
    borrow_history.cpp \
    borrow_info.cpp \
    dboperator.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    managermainwindow.cpp \
    signup.cpp \
    splashscreen.cpp \
    userprofilemanager.cpp\
    readermanager.cpp\
    readerinformationmanageradddatadialog.cpp\
    readerinformationmanagermodifydialog.cpp\

FORMS += \
    bookclassifymanager.ui \
    bookinformationmanager.ui \
    bookinformationmanageradddatadialog.ui \
    bookinformationmanagermodifydialog.ui \
    managermainwindow.ui\
    readermanager.ui\
    readerinformationmanageradddatadialog.ui\
    readerinformationmanagermodifydialog.ui\
    userprofilemanager.ui\
    booksearch.ui \
    borrow_history.ui \
    borrow_info.ui \
    login.ui \
    mainwindow.ui \
    signup.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
