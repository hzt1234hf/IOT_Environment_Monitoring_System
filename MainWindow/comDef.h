#ifndef COMDEF_H
#define COMDEF_H

#include <QDateTime>

typedef struct DatabaseData{
    int data      : 16;
    QDateTime Time;
}DatabaseData;

#endif // COMDEF_H
