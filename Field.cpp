#include "Field.h"
#include <algorithm>

Field::Field(int size):
    size(size)
{
    cells.resize(size);
    for (auto& cell : cells){
        cell.resize(size);
        std::fill(cell.begin(), cell.end(), emptyCellId);
    }

    horizontalBorders.resize(size + 1);
    for (auto& vec : horizontalBorders){
        vec.resize(size);
        std::fill(vec.begin(), vec.end(), uncheckedBorderId);
    }
    std::fill(horizontalBorders.first().begin(), horizontalBorders.first().end(), fieldBorderId);
    std::fill(horizontalBorders.last().begin(), horizontalBorders.last().end(), fieldBorderId);
    //for tests:
//    horizontalBorders[1][0] = 0;
//    horizontalBorders[2][1] = 0;
//    horizontalBorders[3][2] = 0;
//    horizontalBorders[4][5] = 0;


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
        return InvalidPosition;
    }
    if (borderCoords.y() >= vec[borderCoords.x()].size()){
        return InvalidPosition;
    }
    if (vec[borderCoords.x()][borderCoords.y()] != uncheckedBorderId){
        return InvalidPosition;
    }
    vec[borderCoords.x()][borderCoords.y()] = playerId;
    auto points =  checkCellClosing(orientation, borderCoords);
    if (!points.isEmpty()){
        for(const auto& point: points){
            cells[point.x()][point.y()] = playerId;
        }
        return CellClosed;
    }
    return Success;
}

int Field::getCellStatus(QPoint cellCoords) const
{
    if (cellCoords.x() >= cells.size() || cellCoords.y() >= cells.size()){
        throw OutOfBorderExc(cellCoords);
    }
    return cells[cellCoords.x()][cellCoords.y()];
}

std::tuple<const Field::Matrix<int> &, const Field::Matrix<int> &, const Field::Matrix<int> &> Field::getFieldData() const
{
    return std::make_tuple(std::cref(horizontalBorders), std::cref(verticalBorders), std::cref(cells));
}

int Field::getWinnerId() const
{
    return winnerId;
}

QVector<QPoint> Field::checkCellClosing(Field::BorderOrientaion orientation, const QPoint &point)
{
    QVector<QPoint> result;
    if (orientation == Horizontal){
        if (playerOrFieldBorder( BorderOrientaion::Horizontal, point - QPoint(1, 0)) &&
            playerOrFieldBorder( BorderOrientaion::Vertical, QPoint(point.y(), point.x() - 1)) &&
            playerOrFieldBorder( BorderOrientaion::Vertical, QPoint(point.y() + 1, point.x() - 1))){
            result.push_back({point.x() - 1, point.y()});
        }
        if (playerOrFieldBorder( BorderOrientaion::Horizontal, point + QPoint(1, 0)) &&
            playerOrFieldBorder( BorderOrientaion::Vertical, QPoint(point.y(), point.x())) &&
            playerOrFieldBorder( BorderOrientaion::Vertical, QPoint(point.y() + 1, point.x()))){
            result.push_back({point.x(), point.y()});
        }
    } else {
        if (playerOrFieldBorder( BorderOrientaion::Vertical, point - QPoint(1, 0)) &&
            playerOrFieldBorder( BorderOrientaion::Horizontal, QPoint(point.y(), point.x() - 1)) &&
            playerOrFieldBorder( BorderOrientaion::Horizontal, QPoint(point.y() + 1, point.x() - 1))){
            result.push_back({point.y() , point.x()  -1});
        }
        if (playerOrFieldBorder( BorderOrientaion::Vertical, point + QPoint(1, 0)) &&
            playerOrFieldBorder( BorderOrientaion::Horizontal, QPoint(point.y(), point.x())) &&
            playerOrFieldBorder( BorderOrientaion::Horizontal, QPoint(point.y() + 1, point.x()))){
            result.push_back({point.y(), point.x()});
        }
    }
    return result;
}

bool Field::playerOrFieldBorder(Field::BorderOrientaion orientation, const QPoint &point)
{
    return getBordersByOrientation(orientation)[point.x()][point.y()] != uncheckedBorderId;

}

Field::Matrix<int>& Field::getBordersByOrientation(Field::BorderOrientaion orientation)
{
    return orientation == BorderOrientaion::Horizontal ? horizontalBorders : verticalBorders;
}

bool Field::isGameEnded() const
{
    for (const auto& rows : cells){
        for (const auto& cell : rows){
            if (cell == emptyCellId){
                return false;
            }
        }
    }
    return true;
}




