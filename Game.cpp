#include "Engine.h"
#include "SpaceShip.h"
#include "windows.h"
#include <stdlib.h>
#include <memory.h>
#include <chrono>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()


void initialize()
{
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
}

void draw()
{
    boolean running = true;
    while (running)
    {
  // clear backbuffer
  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  SpaceShip ship(Point2D(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2), Point2D(50, 50));



      uint32_t elapsed_secs = static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0);

      if (is_key_pressed(VK_LEFT))
      {
          if (!ship.IsExploded())
          {
              // If we pressed left and the ship is not exploded, we rotate it
              ship.ApplyLeftRotation(elapsed_secs);
          }
      }
      if (is_key_pressed(VK_RIGHT))
      {
          if (!ship.IsExploded())
          {
              // If we pressed right and the ship is not exploded, we rotate it
              ship.ApplyRightRotation(elapsed_secs);
          }
      }

      if (is_key_pressed(VK_ESCAPE)) {
          act(elapsed_secs);
          running = false;
      }
  }


}

void finalize()
{
}

