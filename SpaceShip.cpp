#define _USE_MATH_DEFINES

#include <stdio.h>
#include <utility>
#include <vector>
#include <math.h>

#include "SpaceShip.h"

bool SpaceShip::Update() {
    // erase area
    // Draw() callout

    return true;
};

void SpaceShip::Draw() {
    Point2D headPoint = Point2D(static_cast<uint32_t>(position_.x + 30 * sin(rotation_ * M_PI / 180)),
        static_cast<uint32_t>(position_.y - 30 * cos(rotation_ * M_PI / 180)));
    Point2D leftPoint = Point2D(static_cast<uint32_t>(position_.x + 15 * sin((rotation_ - 120) * M_PI / 180)),
        static_cast<uint32_t>(position_.y - 15 * cos((rotation_ - 120) * M_PI / 180)));
    Point2D rightPoint = Point2D(static_cast<uint32_t>(position_.x + 15 * sin((rotation_ + 120) * M_PI / 180)),
        static_cast<uint32_t>(position_.y - 15 * cos((rotation_ + 120) * M_PI / 180)));

    drawLine(headPoint, leftPoint, color_);
    drawLine(leftPoint, rightPoint, color_);
    drawLine(rightPoint, headPoint, color_);
};

void SpaceShip::Reset()
{
    // Position in the center of the screen
    position_.x = SCREEN_HEIGHT / 2;
    position_.y = SCREEN_WIDTH / 2;

    // Speed = 0, the ship initially doesn't move
    speed_.x = 0;
    speed_.y = 0;

    rotation_ = -90;

    // The ship is not exploded
    exploded_ = false;
};

void SpaceShip::ApplyLeftRotation(float elapsedTime)
{
	// Rotates the ship left
	rotation_ -= elapsedTime * 180;
}

void SpaceShip::ApplyRightRotation(float elapsedTime)
{
	// Rotates the ship right
	rotation_ += elapsedTime * 180;
}

bool SpaceShip::IsExploded() {
	return exploded_;
};

void SpaceShip::ApplyAcceleration(float elapsedTime)
{
	// This accellerates the ship forward. We also cap the speed
	speed_.x += 250 * elapsedTime * sin(rotation_ * M_PI / 180);
	if (speed_.x > 100)
	{
		speed_.x = 100;
	}
	if (speed_.x < -100)
	{
		speed_.x = -100;
	}
	speed_.y -= 250 * elapsedTime * cos(rotation_ * M_PI / 180);
	if (speed_.y > 100)
	{
		speed_.y = 100;
	}
	if (speed_.y < -100)
	{
		speed_.y = -100;
	}
}

void SpaceShip::Move(double elapsedTime)
{
	// Ship moves according to its speed, and if it goes outside the screen, we pop up on the other side of the screen
	position_.x += elapsedTime * speed_.x;
	if (position_.x < -1)
	{
		position_.x = SCREEN_HEIGHT + 1;
	}
	if (position_.x > SCREEN_HEIGHT + 1)
	{
		position_.x = -1;
	}
	position_.y += elapsedTime * speed_.y;
	if (position_.y < -1)
	{
		position_.y = SCREEN_WIDTH + 1;
	}
	if (position_.y > SCREEN_WIDTH + 1)
	{
		position_.y = -1;
	}
	if (this->IsExploded())
	{
		explosionTime_ += elapsedTime;
	}
}