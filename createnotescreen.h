#pragma once
#include <QTextEdit>
#include "createthemescreen.h"
#include "note.h"

class CreateNoteScreen : public CreateThemeScreen {
Q_OBJECT
public:
    CreateNoteScreen(QWidget* parent = nullptr);
signals:
    void createNote(Note note);
private:
    QTextEdit text;
};
