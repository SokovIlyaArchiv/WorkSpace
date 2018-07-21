#include "data.h"

Data::Data(string settingsFileName) {
    ifstream in(settingsFileName);
    if(in.is_open()) {
        string themesListFName;
        in >> password >> themesListFName;
        in.close();
        readThemesList(themesListFName);
        for(auto& themeName : themesFileNames) {
            readTheme(themeName);
        }
    } else {
        cerr << "Settings file not found." << endl;
        exit(0);
    }
}

bool Data::isValid(string password) const {
    if(password == this->password) {
        return true;
    }
    return false;
}

void Data::readThemesList(const string& themesListFName) {
    ifstream in(themesListFName);
    if(in.is_open()) {
        string themeFileName;
        while(in >> themeFileName) {
            themesFileNames.push_back(themeFileName);
        }
    }
}

void Data::readTheme(const string &themeName) {
    themes.push_back(Theme(themeName));
}

const vector<string> Data::getThemesList(string password) const {
    if(isValid(password)) {
        vector<string> answer;
        for(auto theme : themes) {
            answer.push_back(theme.getName(""));
        }
        return answer;
    } else {
        return {};
    }
}

Theme& Data::getTheme(const string &name) {
    for(auto& theme : themes) {
        if(theme.getName("") == name) {
            return theme;
        }
    }
    cerr << "Theme not found: " << name << endl;
    return emptyTheme;
}
