#include "createnotescreen.h"

createNoteScreen::createNoteScreen(QWidget *parent)
    : CreateThemeScreen (parent) {
    CreateThemeScreen::vLayout->removeWidget(CreateThemeScreen::createButton);
    CreateThemeScreen::createButton->deleteLater();
    CreateThemeScreen::createButton = new QPushButton("Create", this);
    CreateThemeScreen::vLayout->addWidget(&text);
    CreateThemeScreen::vLayout->addWidget(CreateThemeScreen::createButton);
    connect(CreateThemeScreen::createButton, &QPushButton::clicked, [=]() {
        Note note;
        note.init(CreateThemeScreen::name->text().toStdString(),
                  text.toPlainText().toStdString(),
                  CreateThemeScreen::date->text().toStdString(),
                  0,
                  0);
        createNote(note);
    });
}
