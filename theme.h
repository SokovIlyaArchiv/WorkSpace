#pragma  once

#include <vector>

#include "note.h"

class Theme {
public:
    Theme() = default;
    Theme(string fileName);
    void init(string name, string date, uint32_t nameCheckSumm, uint32_t notesCheckSumm);
    string getName(string password) const;
    string getDate() const;
    vector<string> getNotesNames(string password) const;
    bool addNote(const Note& note);
    Note getNote(string Name) const;
private:
    string decode(string text, string password) const;
    bool isValid(string text, string password) const;
    uint32_t nameCheckSum, notesCheckSum;
    string name, date;
    vector<Note> notes;
};
