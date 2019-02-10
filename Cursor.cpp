#include "Cursor.h"
#include <QPixmap>



Cursor::Cursor(QSize size):
    cursor (QPixmap(":/pictures/img/cursor.png").scaled(size), 0, 0)
{

}

const QCursor &Cursor::getCursor() const
{
       return cursor;
}

QSize Cursor::getSize() const
{
    return cursor.pixmap().size();
}
