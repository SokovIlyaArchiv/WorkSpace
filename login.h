#pragma once

#include <QLineEdit>
using std::string;

class Login : public QLineEdit{
public:
    Login(QWidget *parent = nullptr);
    QLineEdit passwordLine;
};
