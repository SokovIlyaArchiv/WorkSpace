#include "login.h"
#include <QStyle>

Login::Login(QWidget *parent) :
    QLineEdit(parent) {
    setEchoMode(QLineEdit::Password);
    setAlignment(Qt::AlignmentFlag::AlignCenter);
    resize(200, 40);
}
