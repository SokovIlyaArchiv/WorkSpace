#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
    layout = new QVBoxLayout(this);
    setLayout(layout);
}

void MainWindow::setThemesList(vector<string> themesList) {
    this->themesNamesList = themesList;
    updateUI();
}

void MainWindow::updateUI() {
    buttons.clear();
    for(size_t c = 0; c < themesNamesList.size(); c++) {
        QString text(themesNamesList[c].data());
        buttons.push_back(new QPushButton(text, this));
    }
    for(auto button : buttons) {
        layout->addWidget(button);
    }
}

MainWindow::~MainWindow() {

}
