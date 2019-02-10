#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QWidget>

class FieldView : public QWidget
{
    Q_OBJECT
public:
    explicit FieldView(const class Field& field, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) final;
    void mouseReleaseEvent(QMouseEvent *event) final;
    void mousePressEvent(QMouseEvent *event) final;
private:
    QColor getColorById(int id);
    const class Field& field;
    const QColor player1Color = Qt::red;
    const QColor player2Color = Qt::yellow;
    const QColor borderColor = Qt::black;
    const QColor uncheckedBorderColor = Qt::blue;
    const QColor emptyCellColor = Qt::white;
    const int pixelInCell = 50;
signals:

public slots:
};

#endif // FIELDVIEW_H
