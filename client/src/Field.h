#ifndef FIELD_H
#define FIELD_H
#include <QVector>
#include <QtCore>
#include <array>
#include <exception>
#include <random>

#include "globals.h"

struct OutOfBorderExc : public std::exception
{
    OutOfBorderExc(QPoint point) : point(point) {}
    QPoint point;
    const char* what() const noexcept final {return "Wrong border coords.";}
};

struct WrongIdExc : public std::exception
{
    WrongIdExc(int id) : id(id) {}
    int id;
    const char* what() const noexcept final {return "Wrong player id";}
};

class Field
{
public:
    template <typename T> using Matrix = QVector<QVector<T>>;

    enum MoveResult : quint8 {InvalidPosition, Success, CellClosed, GameFinished};
    enum BorderOrientaion {Horizontal, Vertical};

    Field(int size, const QVector<idT>& ids);
    int getSize() const;
    MoveResult doMove(int playerId, BorderOrientaion orientation, QPoint borderCoords);
    int getCellStatus(QPoint cellCoords) const;
    std::tuple<const Matrix<int>&, const Matrix<int>&, const Matrix<int>&> getFieldData() const;
    idT getWinnerId() const;
    bool isGameEnded() const;
    idT getCurrentPlayerId() const;
    QMap<idT, qint32> getGameStatistics() const;

private:
    Matrix<idT> horizontalBorders;
    Matrix<idT> verticalBorders;
    Matrix<idT> cells;
    const idT uncheckedBorderId = -1;
    const idT emptyCellId = -3;
    const idT fieldBorderId = -2;
    QMap<idT, qint32> playersStats;
    QMap<idT, qint32>::iterator currentPlayer;
    idT winnerId;
    const int size;
    std::mt19937 gen;
    QVector<QPoint> checkCellClosing(Field::BorderOrientaion orientation, const QPoint &point);
    bool playerOrFieldBorder(Field::BorderOrientaion orientation, const QPoint &point);
    Matrix<int>& getBordersByOrientation(Field::BorderOrientaion orientation);
    int countWinnerId() const;
    bool checkEndGame();

};

#endif // FIELD_H
