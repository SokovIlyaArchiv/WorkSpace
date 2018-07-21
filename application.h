#pragma once

#include <QObject>

#include "data.h"
#include "login.h"
#include "mainwindow.h"

class Application : public QObject {
Q_OBJECT

public:
    Application();
public slots:
    void tryToLogin(const QString& password);
private:
    Data data;
    Login login;
    MainWindow mainWindow;
};
