#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
void move(int j, int h, int &x, int &y)
{
    if (j == 1)
        y = y - h;
    else if (j == 2)
        x = x + h;
    else if (j == 3)
        y = y + h;
    else if (j == 4)
        x = x - h;
    lineto(x, y);
}
void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y)
{
    while (i > 0)
    {
        i--;
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(l, h, x, y);
        hilbert(u, l, d, r, i, h, x, y);
    }
}
int main()
{
    int n, x, y;
    int x0 = 50, y0 = 150, h = 10, r = 2, d = 3, l = 4, u = 1;
    cout << "\nGive the value of n: ";
    cin >> n;
    x = x0;
    y = y0;
    int driver = DETECT, mode = 0;
    initgraph(&driver, &mode, NULL);
    moveto(x, y);
    hilbert(r, d, l, u, n, h, x, y);
    getch();
    closegraph();
    return 0;
}