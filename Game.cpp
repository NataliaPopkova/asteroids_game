#include "Logic.h"


// initialize game data in this function
void initialize() {
    //std::srand(std::time(nullptr));

    ship = new SpaceShip();

    asteroids.reserve(100);
    lasers.reserve(50);

    for (int i = 0; i < asteroids_n; i++) {
        asteroids.push_back(Asteroid());
    };

    for (int i = 0; i < lives; i++) {
        lifeShips.push_back(SpaceShip(i));
    }
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt) {
    if (is_key_pressed(VK_ESCAPE))
        schedule_quit_game();

    if (!gameOver) {
        spaceShip_logic(dt);

        laser_logic(dt);

        asteroids_logic(dt);

        asteroids_laser_collision_logic(dt);

        asteroid_ship_collision_logic(dt);
    }
}

void draw() {
    // clear backbuffer
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

    if (!gameOver) {
        ship->Draw();

        for (int i = 0; i < lasers.size(); i++) {
            lasers[i].Draw();
        }

        for (int i = 0; i < asteroids.size(); i++) {
            asteroids[i].Draw();
        }

        for (int i = 0; i < lifeShips.size(); i++) {
            lifeShips[i].Draw();
        }
    } else {
        if (gameWon == true) {
            drawWin();
        }
        else {
            drawLose();
        }
    }
}

// free game data in this function
void finalize() {
    ship->~SpaceShip();
}