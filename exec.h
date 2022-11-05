#ifndef EXEC_H
#define EXEC_H


#include <windows.h>
#include <iostream>

#include <QObject>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QGuiApplication>
#include <QImage>
#include <QMovie>

static const int screen_width = 100;
static const int screen_height = 40;
static const int framerate = 1;
constexpr static const char gradient[10] = { ' ', '.', ':',';','+','x','X','#','%','@' };

class exec : public QObject
{
    Q_OBJECT
public:
    explicit exec(QObject *parent = nullptr);
private:
    //QTimer *timer;
    QPixmap currentImage;
    QMovie *gif;
    char charBuffer[screen_width][screen_height];

private slots:
void DrawScreen();

signals:

};

#endif // EXEC_H
