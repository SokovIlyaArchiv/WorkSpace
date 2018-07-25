#include "createthemescreen.h"

CreateThemeScreen::CreateThemeScreen(QWidget *parent) : QWidget(parent) {
    vLayout = new QVBoxLayout(this);
    nameLayout = new QHBoxLayout(vLayout->widget());
    passwordLayout = new QHBoxLayout(vLayout->widget());
    dateLayout = new QHBoxLayout(vLayout->widget());
    nameLabel = new QLabel("Name: ", this);
    passwordLabel = new QLabel("Password: ", this);
    dateLabel = new QLabel("Date: ", this);
    name = new QLineEdit(this);
    password = new QLineEdit(this);
    date = new QLineEdit(this);
    createButton = new QPushButton("Create", this);
    isNameEncoded = new QCheckBox("Is name encoded?", this);
    isDataEncoded = new QCheckBox("Is data encoded?", this);
    vLayout->addLayout(nameLayout);
    vLayout->addLayout(passwordLayout);
    vLayout->addLayout(dateLayout);
    vLayout->addWidget(isNameEncoded);
    vLayout->addWidget(isDataEncoded);
    vLayout->addWidget(createButton);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(name);
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(password);
    dateLayout->addWidget(dateLabel);
    dateLayout->addWidget(date);

    connect(createButton, &QPushButton::clicked, [=]() {
        Theme theme;
        theme.init(name->text().toStdString(), date->text().toStdString(), 0, 0);
        createTheme(theme);
    });
}
