#include <QGuiApplication>
#include "exec.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);


    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //int screen_width, screen_height;

    //GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //screen_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //screen_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    exec w;
    return a.exec();
}
