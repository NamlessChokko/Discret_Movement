#include "../inc/Basic.hpp"

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>  
#else
    #include <termios.h> 
    #include <unistd.h>
    #include <cstdio>
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

char basic::getch() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
#endif
}

int basic::getTerminalWidth() {
    int width = 80; 

    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        }
    #else
        struct winsize size;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == 0) {
            width = size.ws_col;
        }
    #endif

    return width;
}
