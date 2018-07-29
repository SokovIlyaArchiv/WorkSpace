#include "application.h"

Application::Application() :
    data("settings.txt"), mainWindow(data) {
    login.show();
    connect(&login, &QLineEdit::textChanged, this, &Application::tryToLogin);
}

void Application::tryToLogin(const QString &password) {
    if(data.isValid(password.toStdString())) {
        login.close();
        mainWindow.loginAndShow(password.toStdString());
        cout << "Logined" << endl;
    }
}
