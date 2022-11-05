#include "exec.h"

exec::exec(QObject *parent)
    : QObject{parent}
{
    //hide cursor
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); CONSOLE_CURSOR_INFO cursorInfo; GetConsoleCursorInfo(out, &cursorInfo); cursorInfo.bVisible = false; SetConsoleCursorInfo(out, &cursorInfo);

    gif = new QMovie(":/samples/gif.gif");
    gif->setSpeed(200);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &exec::TimedEvent);
    connect(gif, &QMovie::frameChanged, this, &exec::TimedEvent);
    //gif->start();
    //timer->start(1000/framerate);
    TimedEvent();
}
void exec::TimedEvent()
{
    int buffer[screen_width][screen_height];

    currentImage.load(":/samples/rofl1.jpg");
    QImage _currentImage = currentImage.toImage();//gif->currentImage();currentImage.toImage();
    QImage scaledImage = _currentImage.scaled(screen_width,screen_height);
    QColor colorBuffer[screen_width][screen_height];
    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
        {
            colorBuffer[x][y] = scaledImage.pixel(x,y);
        }
    }

    FillNumericBuffer(buffer, colorBuffer);
}

void exec::DrawScreen(char buffer[screen_width][screen_height])
{
    system("cls");
    for (int _y = 0; _y < screen_height; _y++)
    {
        for (int _x = 0; _x < screen_width; _x++)
        {
            if (_y == screen_height-1 && _x == screen_width-1) { break; } else { std::cout<<(buffer[_x][_y]); }
        }
    }
}

void exec::ConvertNumericToCharBuffer(int buffer[screen_width][screen_height])
{
    char charBuffer[screen_width][screen_height];
    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
        {
            charBuffer[x][y] = gradient[buffer[x][y]];
        }
    }

    DrawScreen(charBuffer);
}

void exec::FillNumericBuffer(int buffer[screen_width][screen_height], QColor colorBuffer[screen_width][screen_height])
{
    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
        {
            int c = colorBuffer[x][y].red()+colorBuffer[x][y].blue()+colorBuffer[x][y].green();
            c = c/(3*26);
            buffer[x][y] = c;
        }
    }
    ConvertNumericToCharBuffer(buffer);
}
