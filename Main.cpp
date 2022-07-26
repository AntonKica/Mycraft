#include "stdint.h"
#include "stdio.h"
#include "X11/Xlib.h"

int main()
{
    Display *Dis = XOpenDisplay(0);
    if(!Dis)
    {
        printf("Unable to open display!");
        return 1;
    }

    Screen *Scr = DefaultScreenOfDisplay(Dis);
    int ScrId = DefaultScreen(Dis);

    Window Win = XCreateSimpleWindow(Dis, RootWindowOfScreen(Scr), 0, 0, 320, 200,
            1, BlackPixel(Dis, ScrId), WhitePixel(Dis, ScrId));
    if(!Win)
    {
        printf("Unable to open window!");
        return 1;
    }
    XClearWindow(Dis, Win);
    XMapRaised(Dis, Win);
    while(true)
    {
        XEvent Ev;
        XNextEvent(Dis, &Ev);
    }

    XDestroyWindow(Dis, Win);
    XFree(Scr);
    XCloseDisplay(Dis);

    return 0;
}
