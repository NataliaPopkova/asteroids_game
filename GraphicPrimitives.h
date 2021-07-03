#pragma once
#include <stdio.h>
#include <math.h>

class Object {
public:
    Object(int x, int y, float speed);
    virtual ~Object();
    virtual void Draw() = 0;
    virtual bool Update();
    
private:
    int x;
    int y;
    float dx;
    float dy;
    double direction;
    float speed;
    int live;
    // COLOR color;
};

enum COLOR {
    BLUE =  0x0000ff,
    RED =   0xff0000,
    GREEN = 0x00ff00,
};

/*
    Bresenham's line algorithm
*/
void drawLine(int x1, int y1, int x2, int y2, COLOR color) {
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    buffer[x2][y2] = color;
    while (x1 != x2 || y1 != y2)
    {
        buffer[x1][y1] = color;
        int error2 = error * 2;
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
};

void drawCircle(int x0, int y0, int radius, COLOR color) {
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while (y >= 0) {
        buffer[x0 + x][y0 + y] = color;
        buffer[x0 + x][y0 - y] = color;
        buffer[x0 - x][y0 + y] = color;
        buffer[x0 - x][y0 - y] = color;

        error = 2 * (delta + y) - 1;
        if (delta < 0 && error <= 0) {
            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if (delta > 0 && error > 0) {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}