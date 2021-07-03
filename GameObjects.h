#pragma once
#include <stdio.h>
#include <utility>

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