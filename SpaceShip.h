#pragma once

#include "GameObjects.h"
#include "GraphicPrimitives.h"


class SpaceShip : public Object {
public:
    SpaceShip(Point2D position, Point2D speed) : position_{ position }, speed_{ speed } {
        Draw();
    };

    ~SpaceShip() = default;

    bool Update() override;

    void Draw() override;

    void ApplyLeftRotation(uint32_t elapsedTime);

    void ApplyRightRotation(uint32_t elapsedTime);

    void ApplyAcceleration(uint32_t elapsedTime);

    void Explode();

    bool IsExploded();

    void Reset();

private:
    COLOR color_{ COLOR::BLUE };

    Point2D position_;
    Point2D speed_;

    double  rotation_{ -90 };
    int hp_;

    bool exploded_{false};

    std::vector<std::pair<int, int>> area;
};