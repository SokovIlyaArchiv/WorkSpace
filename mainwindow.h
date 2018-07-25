#pragma once
#include <string>
#include <vector>

#include "createnotescreen.h"
#include "data.h"

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(Data& data, QWidget *parent = nullptr);
    void setThemesList(vector<string> themesList);
    ~MainWindow();
private slots:
    void addTheme(Theme theme);
    void addNote(Note note);
private:
    void buttonPushed();
    void updateUI();
    void toThemeState(string Theme);
    void toMainWindowState();
    void recreateButtons(vector<string>& buttonsNames);
    void removeFromVector(string element, vector<string>& elementVector);
    bool isRemoveState, isThemeState;
    QVBoxLayout* layout;
    QHBoxLayout* hLayout;
    QPushButton *exit, *add, *remove;
    vector<QPushButton*> buttons;

    vector<string> themesNamesList,
                   notesNamesList;
    Data& data;
    Theme &theme, defaultTheme;
    CreateThemeScreen createThemeScreen;
    createNoteScreen createNoteScreen;
};
