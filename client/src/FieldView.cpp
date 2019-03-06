#include "FieldView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

FieldView::FieldView(const class Field& field, QWidget *parent) : QWidget(parent),
    field(field),
    cursor({20, 20})
{
    setCursor(cursor.getCursor());
}

void FieldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
//    painter.drawRect();
    const auto& [horizontalBorders, verticalBorders, cells] = field.getFieldData();
    if (horizontalBorders.isEmpty() || verticalBorders.isEmpty() || cells.isEmpty()){
        return;
    }
    for (int i = 0; i < horizontalBorders.size(); i++){
        for (int j = 0; j < horizontalBorders[i].size(); j++){
             painter.setPen(getColorById(horizontalBorders[i][j]));
             int delta = i == horizontalBorders.size() - 1 ? 1 : 0;
             painter.drawLine(j * pixelInCell, i * pixelInCell - delta, j * pixelInCell + pixelInCell, i * pixelInCell - delta);
        }
    }
    for (int i = 0; i < verticalBorders.size(); i++){
        for (int j = 0; j < verticalBorders[i].size(); j++){
             painter.setPen(getColorById(verticalBorders[i][j]));
             int delta = i == verticalBorders.size() - 1 ? 1 : 0;
             painter.drawLine(i * pixelInCell - delta, j * pixelInCell, i * pixelInCell - delta, j * pixelInCell + pixelInCell);
        }
    }
    painter.setPen({QBrush(Qt::transparent), 0});
    for (int i = 0; i < cells.size(); i++){
        for (int j = 0; j < cells[i].size(); j++){
             painter.setBrush(getColorById(cells[i][j]));
             painter.drawRect(j * pixelInCell + 2, i * pixelInCell + 2, pixelInCell - 3, pixelInCell - 3);
        }
    }

}

void FieldView::mouseReleaseEvent(QMouseEvent *event)
{
//    QRect pointerRect {event->x(), event->y(), 7, 7};
//    qDebug() << "event: " << event->pos();
//    //    field.doMove(0)
    QWidget::mouseReleaseEvent(event);
//    QRect::intersected()
}

void FieldView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "event: " << event->pos();
    int indexX = event->pos().x() / pixelInCell;
    int indexY = event->pos().y() / pixelInCell;
    QRect topLeft{indexX * pixelInCell, indexY * pixelInCell, pixelInCell, pixelInCell};
    QRect botRight{(indexX + 1) * pixelInCell, (indexY + 1) * pixelInCell, pixelInCell, pixelInCell};
    QRect curs {event->pos(), cursor.getSize()};
    auto tlInt = topLeft.intersected(curs);
    auto brInt = botRight.intersected(curs);
    auto tlSize = getMaxLength(tlInt);
    auto brSize = getMaxLength(brInt);
    QPoint resultPoint;
    Field::BorderOrientaion orient = Field::Horizontal;
    if ((tlSize.second > brSize.second) ){
        if (!topLeft.contains(curs)){
            if (tlSize.first == Field::Horizontal){
                resultPoint = {indexY + 1, indexX};
            } else {
                resultPoint = {indexX + 1, indexY};
            }
            orient = tlSize.first;
        }
    } else {
        if (!botRight.contains(curs)){
            if (brSize.first == Field::Horizontal){
                resultPoint = {indexY + 1, indexX + 1};
            } else {
                resultPoint = {indexX + 1, indexY + 1};
            }
            orient = brSize.first;
        }
    }
    emit doMove(orient, resultPoint);
    event->accept();
}

QColor FieldView::getColorById(int id)
{
    switch (id) {
    case -3:
        return emptyCellColor;
    case -2:
        return borderColor;
    case -1:
        return uncheckedBorderColor;
    case 0:
        return player1Color;
    case 1:
        return player2Color;
    default:
        return {};
        break;
    }
}

std::pair<Field::BorderOrientaion, int> FieldView::getMaxLength(const QRect &rect)
{
    if (rect.width() > rect.height()){
        return {Field::Horizontal, rect.width()};
    } else {
        return {Field::Vertical, rect.height()};
    }
}

