#pragma once

#include <vector>

#include "note.h"

class Theme {
public:
    Theme() {}
    Theme(string fileName);
    void init(string name, string date, uint32_t nameCheckSumm, uint32_t notesCheckSumm);
    string getName(string password) const;
    string getDate() const;
    vector<string> getNotesNames(string password) const;
    void addNote(Note note);
    Note& getNote(string Name);
    void removeNote(string noteName);
private:
    string decode(string text, string password) const;
    bool isValid(string text, string password) const;
    uint32_t nameCheckSum, notesCheckSum;
    string name, date;
    vector<Note> notes;
    Note defaultNote;
};
