#include "noteeditor.h"

NoteEditor::NoteEditor(QWidget *parent)
    : QWidget (parent), layout(this), hLayout(layout.widget()),
      backButton(this), saveButton(this), text(layout.widget()) {
    setLayout(&layout);
    layout.addLayout(&hLayout);
    hLayout.addWidget(&backButton);
    hLayout.addWidget(&saveButton);
    backButton.setText("Back");
    saveButton.setText("Save");
    layout.addWidget(&text);
    connect(&saveButton, &QPushButton::clicked, this, &NoteEditor::save);
    connect(&backButton, &QPushButton::clicked, this, &QWidget::close);
}

void NoteEditor::openNote(Note &note, string password) {
    text.setText(QString(note.getText(password).data()));
    show();
}

void NoteEditor::save() {
    changeNote(text.toPlainText().toStdString()); //Code(text, password);
    close();
}
