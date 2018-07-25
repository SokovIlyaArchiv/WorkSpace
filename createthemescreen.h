#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

#include "theme.h"

class CreateThemeScreen : public QWidget {
    Q_OBJECT
public:
    explicit CreateThemeScreen(QWidget *parent = nullptr);
signals:
    void createTheme(Theme theme);
protected:
    QVBoxLayout *vLayout;
    QHBoxLayout *nameLayout, *passwordLayout, *dateLayout;
    QLabel *nameLabel, *passwordLabel, *dateLabel;
    QLineEdit *name, *password, *date;
    QPushButton *createButton;
    QCheckBox *isNameEncoded, *isDataEncoded;
};
