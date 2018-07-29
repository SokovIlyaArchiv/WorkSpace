#pragma once
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "note.h"

class NoteEditor : public QWidget{
Q_OBJECT
public:
    NoteEditor(QWidget* parent = nullptr);
public slots:
    void openNote(Note& note, string password);
signals:
    void changeNote(string newText);
private:
    void save();
    QVBoxLayout layout;
    QHBoxLayout hLayout;
    QPushButton backButton, saveButton;
    QTextEdit text;
};
