#include "mainwindow.h"

MainWindow::MainWindow(Data& data, QWidget *parent)
    : QWidget(parent), data(data) {
    layout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout(layout->widget());
    exit = new QPushButton("Exit", this);
    add = new QPushButton("Add", this);
    remove = new QPushButton("Remove", this);
    hLayout->addWidget(exit);
    hLayout->addWidget(add);
    hLayout->addWidget(remove);
    layout->addLayout(hLayout);
    connect(exit, &QPushButton::clicked, this, &QWidget::close);
    connect(add, &QPushButton::clicked, &createThemeScreen, &QWidget::show);
    connect(&createThemeScreen, &CreateThemeScreen::createTheme, this, &MainWindow::addTheme);
}

void MainWindow::setThemesList(vector<string> themesList) {
    this->themesNamesList = themesList;
    updateUI();
}

void MainWindow::updateUI() {
    for(auto& button : buttons) {
        layout->removeWidget(button);
    }
    buttons.clear();
    for(auto& themeName : themesNamesList) {
        buttons.push_back(new QPushButton(QString(themeName.data()), this));
    }
    for(auto& button : buttons) {
        layout->addWidget(button);
    }
}


MainWindow::~MainWindow() {

}

void MainWindow::addTheme(Theme theme) {
    themesNamesList.push_back(theme.getName(""));
    updateUI();
}
