#include "theme.h"
#include "theme.h"
#include "theme.h"

Theme::Theme(string fileName) {
    ifstream in(fileName);
    if(in.is_open()) {
        in >> name >> date >> nameCheckSum >> notesCheckSum;
        string noteFName;
        while(in >> noteFName) {
            notes.push_back(Note(noteFName));
        }
    } else {
        cerr << "Can not find file(ThemeName): " << fileName << endl;
    }
}

void Theme::init(string name, string date, uint32_t nameCheckSum, uint32_t notesCheckSum) {
    this->name = name;
    this->date = date;
    this->nameCheckSum = nameCheckSum;
    this->notesCheckSum = notesCheckSum;
}

void Theme::removeNote(string noteName) {
    for(auto e = notes.begin(); e != notes.end(); e++) {
        if((*e).getName("") == noteName) {
            notes.erase(e);
            return;
        }
    }
}

string Theme::getName(string password) const {
    if(isValid(name, password)) {
        return decode(name, password);
    } else {
        return to_string(nameCheckSum);
    }
}

string Theme::getDate() const {
    return date;
}

vector<string> Theme::getNotesNames(string password) const {
    vector<string> result;
    for(auto note : notes) {
        result.push_back(note.getName(password));
    }
    if(isValid(to_string(notesCheckSum), password)) { //!!!
        return result;
    } else {
        return {"Invalid password"}; //!!!
    }
}

bool Theme::isValid(string text, string password) const {
    return text.size() + password.size(); // !!!
}

string Theme::decode(string text, string password) const {
    return text; //!!!
}


void Theme::addNote(Note note) {
    for(auto existNote : notes) {
        if(existNote.getName("") == note.getName("")) {
            return;
        }
    }
    notes.push_back(note);
}

Note& Theme::getNote(string name) {
    for(auto& existNote : notes) {
        if(existNote.getName("") == name) {
            return existNote;
        }
    }
    cout << "Note not found" << endl;
    return defaultNote;
}
