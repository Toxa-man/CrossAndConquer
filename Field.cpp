#include "Field.h"
#include <algorithm>

Field::Field(int size):
    size(size)
{
    cells.resize(size);
    for (auto&& cell : cells){
        cell.resize(size);
        std::fill(cell.begin(), cell.end(), emptyCellId);
    }

    horizontalBorders.resize(size + 1);
    for (int i(0); i < horizontalBorders.size(); i++){
        horizontalBorders[i].resize(size);
        std::fill(horizontalBorders[i].begin(), horizontalBorders[i].end(), uncheckedBorderId);
    }
    std::fill(horizontalBorders.first().begin(), horizontalBorders.first().end(), fieldBorderId);
    std::fill(horizontalBorders.last().begin(), horizontalBorders.last().end(), fieldBorderId);


    verticalBorders.resize(size + 1);
    for (int i(0); i < verticalBorders.size(); i++){
        verticalBorders[i].resize(size);
        std::fill(verticalBorders[i].begin(), verticalBorders[i].end(), uncheckedBorderId);
    }
    std::fill(verticalBorders.first().begin(), verticalBorders.first().end(), fieldBorderId);
    std::fill(verticalBorders.last().begin(), verticalBorders.last().end(), fieldBorderId);
}

int Field::getSize() const
{
    return size;
}

Field::MoveResult Field::doMove(int playerId, Field::BorderOrientaion orientation, QPoint borderCoords)
{
    if (playerId < 0){
        throw WrongIdExc(playerId);
    }
    auto& vec = orientation == Horizontal ? horizontalBorders : verticalBorders;
    if (borderCoords.x() >= vec.size()){
        throw OutOfBorderExc(borderCoords);
    }
    if (borderCoords.y() >= vec[borderCoords.x()].size()){
        throw OutOfBorderExc(borderCoords);
    }
    if (vec[borderCoords.x()][borderCoords.y()] != uncheckedBorderId){
        return InvalidPosition;
    }
    vec[borderCoords.x()][borderCoords.y()] = playerId;
    checkCellClosing(playerId, orientation, borderCoords);
    return Success;
}

int Field::getCellStatus(QPoint cellCoords) const
{
    if (cellCoords.x() >= cells.size() || cellCoords.y() >= cells.size()){
        throw OutOfBorderExc(cellCoords);
    }
    return cells[cellCoords.x()][cellCoords.y()];
}

void Field::checkCellClosing(int playerId, Field::BorderOrientaion orientation, const QPoint &point)
{
    bool isClosed = true;
    if (orientation == Horizontal){
        if (horizontalBorders[point.x() - 1] [point.y()] == playerId &&)
    }

}




