#pragma once

#include "theme.h"


using namespace std;

class Data {
public:
    Data(string settingsFileName);
    void addTheme(Theme theme);
    void removeTheme(string themeName);
    bool isValid(string password) const;
    vector<string> getThemesList(string password) const;
    Theme& getTheme(const string& name);
    virtual ~Data() = default;
private:
    void readThemesList(const string& themesListFName);
    void readTheme(const string& themeName);
    string settingsFileName,
           password;
    vector<string> themesFileNames;
    vector<Theme> themes;
    Theme defaultTheme;
};
