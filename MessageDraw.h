#pragma once

#include "GraphicPrimitives.h"

void drawWin() {
    COLOR color = COLOR::GREEN;
    
    drawLine_d(Point2D_d(214, 263), Point2D_d(284, 477), color);
    drawLine_d(Point2D_d(284, 477), Point2D_d(347, 263), color);
    drawLine_d(Point2D_d(347, 263), Point2D_d(403, 477), color);
    drawLine_d(Point2D_d(403, 477), Point2D_d(479, 263), color);

    drawLine_d(Point2D_d(511, 263), Point2D_d(511, 477), color);

    drawLine_d(Point2D_d(561, 263), Point2D_d(561, 477), color);
    drawLine_d(Point2D_d(561, 263), Point2D_d(735, 477), color);
    drawLine_d(Point2D_d(735, 477), Point2D_d(735, 263), color);
};

void drawLose() {
    COLOR color = COLOR::RED;

    drawLine_d(Point2D_d(186, 263), Point2D_d(186, 477), color);
    drawLine_d(Point2D_d(186, 477), Point2D_d(315, 477), color);

    drawLine_d(Point2D_d(360, 263), Point2D_d(360, 477), color);
    drawLine_d(Point2D_d(360, 477), Point2D_d(488, 477), color);
    drawLine_d(Point2D_d(488, 477), Point2D_d(488, 263), color);
    drawLine_d(Point2D_d(488, 263), Point2D_d(360, 263), color);

    drawLine_d(Point2D_d(662, 263), Point2D_d(531, 263), color);
    drawLine_d(Point2D_d(531, 263), Point2D_d(531, 353), color);
    drawLine_d(Point2D_d(531, 353), Point2D_d(662, 353), color);
    drawLine_d(Point2D_d(662, 353), Point2D_d(662, 477), color);
    drawLine_d(Point2D_d(662, 477), Point2D_d(531, 477), color);

    drawLine_d(Point2D_d(693, 263), Point2D_d(840, 263), color);
    drawLine_d(Point2D_d(693, 263), Point2D_d(693, 477), color);
    drawLine_d(Point2D_d(693, 353), Point2D_d(840, 353), color);
    drawLine_d(Point2D_d(693, 477), Point2D_d(840, 477), color);
}