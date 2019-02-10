#ifndef FIELD_H
#define FIELD_H
#include <QVector>
#include <QtCore>
#include <exception>

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
    enum MoveResult {InvalidPosition, Success, CellClosed};
    enum BorderOrientaion {Horizontal, Vertical};
    Field(int size);
    int getSize() const;
    MoveResult doMove(int playerId, BorderOrientaion orientation, QPoint borderCoords);
    int getCellStatus(QPoint cellCoords) const;
    std::tuple<const Matrix<int>&, const Matrix<int>&, const Matrix<int>&> getFieldData() const;
    int getWinnerId() const;
    bool isGameEnded() const;
    //debug:

private:
    Matrix<int> horizontalBorders;
    Matrix<int> verticalBorders;
    Matrix<int> cells;
    const int uncheckedBorderId = -1;
    const int emptyCellId = -3;
    const int fieldBorderId = -2;
    int winnerId = -1;
    int size;
    QVector<QPoint> checkCellClosing(Field::BorderOrientaion orientation, const QPoint &point);
    bool playerOrFieldBorder(Field::BorderOrientaion orientation, const QPoint &point);
    Matrix<int>& getBordersByOrientation(Field::BorderOrientaion orientation);
    int countWinnerId() const;

};

#endif // FIELD_H
