#pragma once
#include <string>
#include <vector>

#include "noteeditor.h"
#include "createnotescreen.h"
#include "data.h"

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(Data& data, QWidget *parent = nullptr);
    void loginAndShow(string password);
    ~MainWindow();
private slots:
    void addTheme(Theme theme);
    void addNote(Note note);
private:
    void buttonPushed();
    void updateUI();
    void toThemeState(string Theme);
    void toMainWindowState();
    void recreateButtons(vector<string> buttonsNames);

    string password;
    bool isRemoveState, isThemeState;

    QVBoxLayout* layout;
    QHBoxLayout* hLayout;
    QPushButton *exit, *add, *remove;
    vector<QPushButton*> buttons;

    Data& data;
    string themeName, noteName;

    CreateThemeScreen createThemeScreen;
    CreateNoteScreen createNoteScreen;
    NoteEditor noteEditor;
};
