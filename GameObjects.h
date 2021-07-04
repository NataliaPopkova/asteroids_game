#pragma once

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <utility>
#include <vector>
#include <math.h>

class Object {
public:
    virtual ~Object() {};
    virtual void Draw() = 0;
    virtual bool Update() = 0;
};