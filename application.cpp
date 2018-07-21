#include "application.h"

Application::Application() :
    data("settings.txt") {
    login.show();
    connect(&login, &QLineEdit::textChanged, this, &Application::tryToLogin);
}

void Application::tryToLogin(const QString &password) {
    if(data.isValid(password.toStdString())) {
        login.close();
        mainWindow.setThemesList(data.getThemesList(password.toStdString()));
        mainWindow.show();
        cout << "Logined" << endl;
    }
}
