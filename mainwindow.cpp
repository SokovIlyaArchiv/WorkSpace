#include "mainwindow.h"

MainWindow::MainWindow(Data& data, QWidget *parent)
    : QWidget(parent), isRemoveState(false), isThemeState(false),
      data(data), theme(defaultTheme) {
    layout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout(layout->widget());
    exit = new QPushButton("Exit", this);
    add = new QPushButton("Add", this);
    remove = new QPushButton("Remove", this);
    hLayout->addWidget(exit);
    hLayout->addWidget(add);
    hLayout->addWidget(remove);
    layout->addLayout(hLayout);
    connect(remove, &QPushButton::clicked, [this](){
        if(isRemoveState) {
            remove->setText("Remove");
        } else {
            remove->setText("Back");
        }
        isRemoveState = !isRemoveState;
    });
    connect(&createThemeScreen, &CreateThemeScreen::createTheme, this, &MainWindow::addTheme);
    connect(&createNoteScreen, &createNoteScreen::createNote, this, &MainWindow::addNote);
    toMainWindowState();
}

void MainWindow::setThemesList(vector<string> themesList) {
    this->themesNamesList = themesList;
    updateUI();
}

void MainWindow::buttonPushed() {
        auto sender = this->sender();
        for(auto button = buttons.begin(); button != buttons.end(); ++button) {
            if(*button == sender) {
                if(isRemoveState) {
                    auto remBntName = (*button)->text().toStdString();
                    removeFromVector(remBntName, (isThemeState)? notesNamesList : themesNamesList);
                    updateUI();
                    isRemoveState = false;
                    remove->setText("Remove");
                    return;
                } else {
                    if(!isThemeState) {
                        toThemeState((*button)->text().toStdString());
                        return;
                    } else {
                        cout << "Opening: " << (*button)->text().toStdString() << endl;
                    }
                }
            }
        }
}

void MainWindow::updateUI() {
    recreateButtons((isThemeState)? notesNamesList : themesNamesList);
}

void MainWindow::toThemeState(string themeName) {
    theme = data.getTheme(themeName);
    notesNamesList = theme.getNotesNames(""); //password
    exit->setText("Back");
    disconnect(exit, &QPushButton::clicked, this, &QWidget::close);
    disconnect(add, &QPushButton::clicked, &createThemeScreen, &QWidget::show);
    connect(exit, &QPushButton::clicked, this, &MainWindow::toMainWindowState);
    connect(add, &QPushButton::clicked, &createNoteScreen, &QWidget::show);
    isThemeState = true;
    updateUI();
}

void MainWindow::toMainWindowState() {
    if(isThemeState) {
        disconnect(exit, &QPushButton::clicked, this, &MainWindow::toMainWindowState);
        disconnect(add, &QPushButton::clicked, &createNoteScreen, &QWidget::show);
        isThemeState = false;
    }
    connect(exit, &QPushButton::clicked, this, &QWidget::close);
    connect(add, &QPushButton::clicked, &createThemeScreen, &QWidget::show);
    exit->setText("Exit");
    updateUI();
}

void MainWindow::recreateButtons(vector<string> &buttonsNames) {
    for(auto& button : buttons) {
        layout->removeWidget(button);
        button->deleteLater();
    }
    buttons.clear();
    for(auto& themeName : buttonsNames) {
        buttons.push_back(new QPushButton(QString(themeName.data()), this));
    }
    for(auto& button : buttons) {
        layout->addWidget(button);
        connect(button, &QPushButton::clicked, this, &MainWindow::buttonPushed);
    }
}

void MainWindow::removeFromVector(string element, vector<string> &elementVector) {
    for(auto e = elementVector.begin(); e != elementVector.end(); e++) {
        if(*e == element) {
            elementVector.erase(e);
            return;
        }
    }
}


MainWindow::~MainWindow() {
}

void MainWindow::addTheme(Theme theme) {
    auto themeName = theme.getName("");
    for(auto& name : themesNamesList) { //All themes have unique name
        if(name == themeName) {
            return;
        }
    }
    themesNamesList.push_back(theme.getName(""));
    updateUI();
    data.addTheme(theme);
    //Save to file...
}

void MainWindow::addNote(Note note) {
    auto noteName = note.getName("");
    for(auto& name : theme.getNotesNames("")) { //All themes have unique name
        if(name == noteName) {
            return;
        }
    }
    notesNamesList.push_back(note.getName(""));
    theme.addNote(note);
    updateUI();
}
