#ifndef FIELD_H
#define FIELD_H
#include <QVector>
#include <exception>

struct OutOfBorderExc : public std::exception
{
    OutOfBorderExc(QPoint point) : point(point) {}
    QPoint point;
    const char* what() const final {return "Wrong border coords.";}
};

struct WrongIdExc : public std::exception
{
    WrongIdExc(int id) : id(id) {}
    int id;
    const char* what() const final {return "Wrong player id";}
};

class Field
{
public:
    enum MoveResult {InvalidPosition, Success};
    enum BorderOrientaion {Horizontal, Vertical};
    Field(int size);
    static const inline int uncheckedBorderId = -1;
    static const inline int emptyCellId = -1;
    static const inline int fieldBorderId = -2;
    int getSize() const;
    MoveResult doMove(int playerId, BorderOrientaion orientation, QPoint borderCoords);
    int getCellStatus(QPoint cellCoords) const;
private:
    QVector<QVector<int>> horizontalBorders;
    QVector<QVector<int>> verticalBorders;
    QVector<QVector<int>> cells;
    int size;
    void checkCellClosing(int playerId, Field::BorderOrientaion orientation, const QPoint &point);

};

#endif // FIELD_H
