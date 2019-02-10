#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QWidget>
#include "Field.h"
#include "Cursor.h"

class FieldView : public QWidget
{
    Q_OBJECT
public:
    explicit FieldView(const Field& field, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) final;
    void mouseReleaseEvent(QMouseEvent *event) final;
    void mousePressEvent(QMouseEvent *event) final;
signals:
    void doMove(Field::BorderOrientaion orientation, QPoint borderCoords);
private:
    QColor getColorById(int id);
    static std::pair<Field::BorderOrientaion, int> getMaxLength(const QRect& rect);
    const Field& field;
    const QColor player1Color = Qt::red;
    const QColor player2Color = Qt::yellow;
    const QColor borderColor = Qt::black;
    const QColor uncheckedBorderColor = Qt::blue;
    const QColor emptyCellColor = Qt::white;
    const int pixelInCell = 50;
    Cursor cursor;
signals:

public slots:
};

#endif // FIELDVIEW_H
