#pragma once
#include <string>
#include <vector>

#include "createthemescreen.h"
#include "data.h"

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(Data& data, QWidget *parent = nullptr);
    void setThemesList(vector<string> themesList);
    void updateUI();
    ~MainWindow();
public slots:
    void addTheme(Theme theme);
private:
    QVBoxLayout* layout;
    QHBoxLayout* hLayout;
    QPushButton *exit, *add, *remove;
    vector<QPushButton*> buttons;

    vector<string> themesNamesList;
    Data& data;

    CreateThemeScreen createThemeScreen;
};
