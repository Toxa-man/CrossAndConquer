#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "Field.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<class FieldView> fieldView;
    const int fieldSize = 8;
    const int cellBoardInPixels = 50;
    Field field{fieldSize};
    void mousePressEvent(QMouseEvent *event) final;
    void createField();
    void redrawField();
};

#endif // MAINWINDOW_H
