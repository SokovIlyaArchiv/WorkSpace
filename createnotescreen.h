#pragma once
#include <QTextEdit>
#include "createthemescreen.h"
#include "note.h"

class createNoteScreen : public CreateThemeScreen {
Q_OBJECT
public:
    createNoteScreen(QWidget* parent = nullptr);
signals:
    void createNote(Note note);
private:
    QTextEdit text;
};
