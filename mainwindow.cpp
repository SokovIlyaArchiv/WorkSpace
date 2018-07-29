#include "mainwindow.h"

MainWindow::MainWindow(Data& data, QWidget *parent)
    : QWidget(parent), isRemoveState(false), isThemeState(false),
      data(data) {
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
    connect(&createNoteScreen, &CreateNoteScreen::createNote, this, &MainWindow::addNote);
    connect(&noteEditor, &NoteEditor::changeNote, [=](string text) {
        this->data.getTheme(themeName).getNote(noteName).setText(text);
        cout << text << endl;
    });
}

void MainWindow::loginAndShow(string password) {
    this->password = password;
    toMainWindowState();
    show();
}

void MainWindow::buttonPushed() {
        auto sender = this->sender();
        for(auto button = buttons.begin(); button != buttons.end(); ++button) {
            if(*button == sender) {
                if(isRemoveState) {
                    auto remBntName = (*button)->text().toStdString();
                    if(isThemeState) {
                        data.getTheme(themeName).removeNote(remBntName);
                    } else {
                        data.removeTheme(remBntName);
                    }
                    isRemoveState = false;
                    remove->setText("Remove");
                    recreateButtons((isThemeState)? data.getTheme(themeName).getNotesNames(password)
                                                  : data.getThemesList(password));
                    return;
                } else {
                    if(!isThemeState) {
                        toThemeState((*button)->text().toStdString());
                        return;
                    } else {
                        this->noteName = (*button)->text().toStdString();
                        noteEditor.openNote(data.getTheme(themeName).getNote(noteName), password);
                    }
                }
            }
        }
}

void MainWindow::toThemeState(string themeName) {
    this->themeName = themeName;
    exit->setText("Back");
    disconnect(exit, &QPushButton::clicked, this, &QWidget::close);
    disconnect(add, &QPushButton::clicked, &createThemeScreen, &QWidget::show);
    connect(exit, &QPushButton::clicked, this, &MainWindow::toMainWindowState);
    connect(add, &QPushButton::clicked, &createNoteScreen, &QWidget::show);
    isThemeState = true;
    recreateButtons(data.getTheme(themeName).getNotesNames(password));
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
    recreateButtons(data.getThemesList(password));
}

void MainWindow::recreateButtons(vector<string> buttonsNames) {
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

MainWindow::~MainWindow() {
}

void MainWindow::addTheme(Theme theme) {
    auto themeName = theme.getName(password);
    for(auto& name : data.getThemesList(password)) { //All themes have unique name
        if(name == themeName) {
            cerr  << "It's not unique name for theme" << endl;
            return;
        }
    }
    data.addTheme(theme);
    recreateButtons(data.getThemesList(password));
    createThemeScreen.close();
    //Save to file...
}

void MainWindow::addNote(Note note) {
    auto noteName = note.getName(password);
    for(auto& name : data.getTheme(themeName).getNotesNames(password)) { //All themes have unique name
        if(name == noteName) {
            cerr  << "It's not unique name for note" << endl;
            return;
        }
    }
    data.getTheme(themeName).addNote(note);
    recreateButtons(data.getTheme(themeName).getNotesNames(password));
    createNoteScreen.close();
    //Save to file
}
