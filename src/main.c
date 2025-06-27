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
  if (user_option == LEADERBOARD)
    OpenLeaderboard();
}

int GameMenu() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MENU");
  Texture2D title_texture = LoadTexture("sprites\\inf_man.png");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    int title_texture_pos_x = SCREEN_WIDTH / 2.0f - 495 / 2.0f;
    int play_button_width = MeasureText("PLAY", 30) / 2.0f;
    int play_button_pos_x = SCREEN_WIDTH / 2.0f - play_button_width;
    int leaderboard_button_width = MeasureText("LEADERBOARD", 30) / 2.0f;
    int leaderboard_button_pos_x = SCREEN_WIDTH / 2.0f - leaderboard_button_width;
    int exit_button_width = MeasureText("EXIT", 30) / 2.0f;
    int exit_button_pos_x = SCREEN_WIDTH / 2.0f - exit_button_width;
    DrawTexture(title_texture, title_texture_pos_x,
                100, RAYWHITE);
    Rectangle play_button_rec = (Rectangle) {
      play_button_pos_x,
      280, MeasureText("PLAY", 30), 30
    };
    Rectangle leaderboard_button_rec = (Rectangle) {
      leaderboard_button_pos_x,
      360, MeasureText("LEADERBOARD", 30), 30
    };
    Rectangle exit_button_rec = (Rectangle) {
      exit_button_pos_x,
      440, MeasureText("EXIT", 30), 30
    };
    if (CheckCollisionPointRec(GetMousePosition(), play_button_rec)) {
      DrawText("PLAY", play_button_pos_x,
               280, 30, LIGHTGRAY);
    } else {
      DrawText("PLAY", play_button_pos_x,
               280, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), leaderboard_button_rec)) {
      DrawText("LEADERBOARD", leaderboard_button_pos_x,
               360, 30, LIGHTGRAY);
    } else {
      DrawText("LEADERBOARD", leaderboard_button_pos_x,
               360, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), exit_button_rec)) {
      DrawText("EXIT", exit_button_pos_x,
               440, 30, LIGHTGRAY);
    } else {
      DrawText("EXIT", exit_button_pos_x,
               440, 30, RAYWHITE);
    }
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

void OpenLeaderboard() {
  
}