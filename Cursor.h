#ifndef CURSOR_H
#define CURSOR_H

#include <QCursor>
#include <QSize>
class Cursor
{
public:
    Cursor(QSize size = {20, 20});
    const QCursor& getCursor() const;
    QSize getSize() const;
private:
    QCursor cursor;

};

#endif // CURSOR_H
