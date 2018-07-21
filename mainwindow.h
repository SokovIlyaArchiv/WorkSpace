#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <string>
#include <vector>

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setThemesList(vector<string> themesList);
    void updateUI();
    ~MainWindow();
private:
    QVBoxLayout* layout;
    vector<QPushButton*> buttons;
    vector<string> themesNamesList;
};
