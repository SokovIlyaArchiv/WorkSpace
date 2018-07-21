#pragma once
#include <fstream>
#include <iostream>

using namespace std;
class Note {
public:
    Note() = default;
    Note(string fileName);
    void init(string name, string text, string date, unsigned textCheckSum = 0, unsigned nameCheckSum = 0);
    string getName(string password) const;
    string getText(string password) const;
    string getDate() const;
private:
    bool isValid(string text, string password) const;
    string decode(string text, string password) const;
    string name,
           text,
           date;
    uint32_t nameCheckSum,
             textCheckSum;
};
