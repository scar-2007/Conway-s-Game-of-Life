#include <raylib.h>
#include "simulation.hpp"

int main() 
{
  const int window_height = 750;
  const int window_width = 750;
  const int cell_size = 25;
  int fps = 12;
  Color grey = {29,29,29,255};

  InitWindow(window_width , window_height , "game of life");
  SetTargetFPS(fps);
  Simulation simulation {window_width , window_height , cell_size};


  //simu. loop 
  while(WindowShouldClose() == false)
  {
    //event
    if(IsKeyPressed(KEY_ENTER))
    {
      simulation.Start();
      SetWindowTitle("game of life is running...");
    }
    else if(IsKeyPressed(KEY_SPACE))
    {
      simulation.Stop();
      SetWindowTitle("game of life has stopped");
    }
    else if(IsKeyPressed(KEY_F))
    {
      fps += 2;
      SetTargetFPS(fps);
    }
    else if(IsKeyPressed(KEY_S))
    {
      if(fps > 5)
      {
        fps -= 2;
        SetTargetFPS(fps);
      }
    }
    
    //update state
    simulation.Update();

    //draw
    BeginDrawing();
    ClearBackground(grey);
    simulation.Draw();
    EndDrawing();
  }

  CloseWindow();
}