#pragma once
#include <stdio.h>

#include <iostream>
#include <math.h>
#include <cstdlib>

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
    BLUE = (255, 51, 51),
    RED = (51, 51, 255),
    GREEN = (0, 255, 0),
};

struct line {
public:
    line() {};
    line(uint32_t x_start, uint32_t y_start, uint32_t x_end, uint32_t y_end) :
        x_start_{ x_start }, y_start_{ y_start }, x_end_{ x_end }, y_end_{ y_end } {};
    ~line() = default;

    void draw(COLOR color) {
        for (int i = 0; i < x_end_ - x_start_; i++) {
            for (int j = 0; j < y_end_ - y_start_; j++) {
                buffer[x_start_ + i][y_start_ + j] = color;
            };
        };
    };

private:
    uint32_t x_start_{ 0 };
    uint32_t y_start_{ 0 };
    uint32_t x_end_  { 0 };
    uint32_t y_end_  { 0 };
};

