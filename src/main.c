#include <stdio.h> //library for printing
#include <math.h>
#include <stdbool.h>
#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include "prototypes.h"
#include "structs.h"

int main() {
  int user_option;
  user_option = GameMenu();
  if (user_option == EXIT)
    return 0;    
}

int GameMenu() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MENU");
  Texture2D title_texture = LoadTexture("sprites\\inf_man.png");
  SetTargetFPS(60);
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawTexture(title_texture, SCREEN_WIDTH / 2.0f - 495 / 2.0f,
                100, RAYWHITE);
    DrawText("PLAY", SCREEN_WIDTH / 2.0f - MeasureText("PLAY", 30) / 2.0f,
             280, 30, RAYWHITE);
    DrawText("LEADERBOARD", SCREEN_WIDTH / 2.0f -  MeasureText("LEADERBOARD", 30) / 2.0f,
             360, 30, RAYWHITE);
    DrawText("EXIT", SCREEN_WIDTH / 2.0f - MeasureText("EXIT", 30) / 2.0f,
             440, 30, RAYWHITE);
    Rectangle play_button_rec = (Rectangle) {
      SCREEN_WIDTH / 2.0f - MeasureText("PLAY", 30) / 2.0f,
      280, MeasureText("PLAY", 30), 30};
    Rectangle leaderboard_button_rec = (Rectangle) {
      SCREEN_WIDTH / 2.0f -  MeasureText("LEADERBOARD", 30) / 2.0f,
      360, MeasureText("LEADERBOARD", 30), 30};
    Rectangle exit_button_rec = (Rectangle) {
      SCREEN_WIDTH / 2.0f - MeasureText("EXIT", 30) / 2.0f,
      440, MeasureText("EXIT", 30), 30};
      
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (CheckCollisionPointRec(GetMousePosition(), play_button_rec))
        return PLAY;
      if (CheckCollisionPointRec(GetMousePosition(), leaderboard_button_rec))
        return LEADERBOARD;
      if (CheckCollisionPointRec(GetMousePosition(), exit_button_rec))
        return EXIT;
		}
    EndDrawing();
  }
  UnloadTexture(title_texture);
  CloseWindow();
  return 0;
}




