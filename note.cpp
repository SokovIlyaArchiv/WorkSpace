#include "note.h"

Note::Note(string fileName) {
    ifstream in(fileName);
    if(in.is_open()) {
        in >> name >> text >> date >> textCheckSum >> nameCheckSum;
    } else {
        cerr << "Note file not found: " << fileName << endl;
    }
}

void Note::init(string name, string text, string date, uint32_t textCheckSum, uint32_t nameCheckSum) {
    this->name = name;
    this->text = text;
    this->date = date;
    this->textCheckSum = textCheckSum;
    this->nameCheckSum = nameCheckSum;
}

string Note::getName(string password) const {
    if(isValid(name, password)) {
        return decode(name, password);
    } else {
        return to_string(nameCheckSum);
    }
}

string Note::getText(string password) const {
    if(isValid(text, password)) {
        return decode(text, password);
    } else {
        return to_string(textCheckSum);
    }
}

string Note::getDate() const {
    return date;
}

bool Note::isValid(string text, string password) const {
    return text.size() + password.size(); // !!!
}

string Note::decode(string text, string password) const {
    return text; //!!!
}
