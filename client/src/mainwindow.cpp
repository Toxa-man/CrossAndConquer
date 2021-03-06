#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FieldView.h"
#include <QMouseEvent>

#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    cursor({20, 20}),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fieldView = std::make_unique<FieldView>(field, this);
    qDebug() << "random pick: " << field.getCurrentPlayerId();
    connect(ui->moveBtn, &QPushButton::clicked, [&](){
       auto dir = ui->hor->isChecked() ? Field::Horizontal : Field::Vertical;
       switch (field.doMove(ui->idEdit->text().toInt(), dir, {ui->xEdit->text().toInt(), ui->yEdit->text().toInt()})) {
       case Field::MoveResult::Success: fieldView->update(); break;
       case Field::MoveResult::InvalidPosition: qDebug() << "invalid position"; break;
       case Field::CellClosed: fieldView->update(); qDebug() << "cell closed"; break;
       }
    });

    connect(fieldView.get(), &FieldView::doMove, [&](Field::BorderOrientaion orientation, QPoint borderCoords){
       qDebug() << "current move id: " << field.getCurrentPlayerId();
       switch (field.doMove(field.getCurrentPlayerId(), orientation, borderCoords)) {
       case Field::MoveResult::Success: fieldView->update(); break;
       case Field::MoveResult::InvalidPosition: qDebug() << "invalid position"; break;
       case Field::CellClosed: fieldView->update(); qDebug() << "cell closed"; break;
       case Field::GameFinished: fieldView->update(); qDebug() << "game finished, winner id: " << field.getWinnerId();
       }
    });
    createField();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "from here: " << event->pos();
}

void MainWindow::createField()
{
   fieldView->setFixedSize({fieldSize * cellBoardInPixels, fieldSize * cellBoardInPixels});
   fieldView->move({200, 200});
//    ui->fieldWidget->set

}

