#include <QLabel>
#include <QPixmap>
#include <QString>

#include <string>
#include <iostream>

#include "Game.h"
#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(const labyrinth::model::Game &game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    game_{game}
{
    ui->setupUi(this);
    setupBoard();
}

GameWindow::~GameWindow()
{
    delete ui;
}

static QPixmap getImage(const QString &path) {
    QPixmap image;
    if (!image.load(path)) {
        throw std::invalid_argument(path.toStdString() + " cannot be loaded!\n");
    }
    return image.scaled(50, 50);
}

void GameWindow::setupBoard() {
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            QLabel *label = new QLabel();
            label->setPixmap(getImage(":/resources/images/T.png"));
            ui->board->addWidget(label, row, col);
        }
    }
}