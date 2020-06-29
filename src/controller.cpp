#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const
{
  if (snake.direction != opposite || snake.size == 1)
    snake.direction = input;
  return;
}

void Controller::HandleInput(bool &movement, Snake &snake) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      movement = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      if(e.key.keysym.sym == SDLK_UP){
        ChangeDirection(snake, Snake::Direction::kUp,
                        Snake::Direction::kDown);
      }

      else if(e.key.keysym.sym == SDLK_DOWN){
        ChangeDirection(snake, Snake::Direction::kDown,
                        Snake::Direction::kUp);
      }

      else if(e.key.keysym.sym == SDLK_LEFT){
        ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
      }

      else if(e.key.keysym.sym == SDLK_RIGHT){
        ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
        
      }
    }
  }
}