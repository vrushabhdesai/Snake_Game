#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <string>
#include <iostream>

class Platform
{
public:
    Platform() : platformUsed(std::string())
    {
        platformUsed = getPlatform();
    }
    std::string getPlatform();
    void printPlatform();

private:
    std::string platformUsed;
};


class Game
{
public:
  Game(std::size_t width, std::size_t height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void UpdateStartSpeed();

private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 eng;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};


#endif