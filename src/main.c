// TODO: FIX TABS OPENING OVER ONE ANOTHER -> FIXED

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include "structs.h"

int GameMenu() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MENU");
  char title_location[] = "sprites\\inf_man.png";
  Texture2D title_texture = LoadTexture(title_location);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    int title_texture_x_position = SCREEN_WIDTH/2.0f -
                                   495/2.0f;
    int play_button_width = MeasureText("PLAY", 30);
    int play_button_x_position = SCREEN_WIDTH/2.0f -
                                 play_button_width/2.0f;
    int leaderboard_button_width = MeasureText(
                                   "LEADERBOARD", 30);
    int leaderboard_button_x_position = SCREEN_WIDTH/2.0f -
                             leaderboard_button_width/2.0f;
    int exit_button_width = MeasureText("EXIT", 30);
    int exit_button_x_position = SCREEN_WIDTH/2.0f -
                                 exit_button_width/2.0f;
    DrawTexture(title_texture, title_texture_x_position,
                100, RAYWHITE);
    Rectangle play_button_rectangle = (Rectangle) {
      play_button_x_position, 280, play_button_width, 30
    };
    Rectangle leaderboard_button_rectangle = (Rectangle) {
      leaderboard_button_x_position, 360,
      leaderboard_button_width, 30
    };
    Rectangle exit_button_rectangle = (Rectangle) {
      exit_button_x_position, 440, exit_button_width, 30
    };
    if (CheckCollisionPointRec(GetMousePosition(),
        play_button_rectangle)) {
      DrawText("PLAY", play_button_x_position,
               280, 30, LIGHTGRAY);
    } else {
      DrawText("PLAY", play_button_x_position,
               280, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), 
        leaderboard_button_rectangle)) {
      DrawText("LEADERBOARD", leaderboard_button_x_position,
              360, 30, LIGHTGRAY);
    } else {
      DrawText("LEADERBOARD", leaderboard_button_x_position,
               360, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(),
        exit_button_rectangle)) {
      DrawText("EXIT", exit_button_x_position,
               440, 30, LIGHTGRAY);
    } else {
      DrawText("EXIT", exit_button_x_position,
               440, 30, RAYWHITE);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (CheckCollisionPointRec(GetMousePosition(),
          play_button_rectangle)) {
        return PLAY_RETURN;
      }
      if (CheckCollisionPointRec(GetMousePosition(),
          leaderboard_button_rectangle)) {
        CloseWindow();
        return LEADERBOARD_RETURN;
      }
      if (CheckCollisionPointRec(GetMousePosition(),
          exit_button_rectangle)) {
        return EXIT_RETURN;
      }
    }
    EndDrawing();
  }
  CloseWindow();
  UnloadTexture(title_texture);
  return 0;
}

void ReadBinaryFile(LEADERBOARD_STRUCT
                    leaderboard_struct[NUMERO_JOGADORES]) {
  FILE* leaderboard_file;
  leaderboard_file = fopen("scores.bin", "rb");
  fread(leaderboard_struct, sizeof(LEADERBOARD_STRUCT),
        NUMERO_JOGADORES, leaderboard_file);
  fclose(leaderboard_file);
}

void PrintLeaderboard(LEADERBOARD_STRUCT
                      leaderboard_struct[NUMERO_JOGADORES]) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LEADERBOARD");
	SetTargetFPS(60);
  while (!WindowShouldClose()) {
    ClearBackground(DARKBLUE);
    DrawText(leaderboard_struct[0].player_name, SCREEN_WIDTH/2 -
             MeasureText(leaderboard_struct[0].player_name, 10),
             100, 10, WHITE);
    DrawText(TextFormat("%i", leaderboard_struct[0].player_score),
             SCREEN_WIDTH / 2 + 20, 100, 10, WHITE);
    DrawText(leaderboard_struct[1].player_name, SCREEN_WIDTH/2 -
             MeasureText(leaderboard_struct[1].player_name, 10),
             180, 10, WHITE);
    DrawText(TextFormat("%i", leaderboard_struct[1].player_score),
             SCREEN_WIDTH / 2 + 20, 180, 10, WHITE);
    DrawText(leaderboard_struct[2].player_name, SCREEN_WIDTH/2 -
             MeasureText(leaderboard_struct[2].player_name, 10),
             260, 10, WHITE);
    DrawText(TextFormat("%i", leaderboard_struct[2].player_score),
             SCREEN_WIDTH / 2 + 20, 260, 10, WHITE);
    DrawText(leaderboard_struct[3].player_name, SCREEN_WIDTH/2 -
             MeasureText(leaderboard_struct[3].player_name, 10),
             340, 10, WHITE);
    DrawText(TextFormat("%i", leaderboard_struct[3].player_score),
             SCREEN_WIDTH / 2 + 20, 340, 10, WHITE);
    DrawText(leaderboard_struct[4].player_name, SCREEN_WIDTH/2 -
             MeasureText(leaderboard_struct[4].player_name, 10),
             420, 10, WHITE);
    DrawText(TextFormat("%i", leaderboard_struct[4].player_score),
             SCREEN_WIDTH / 2 + 20, 420, 10, WHITE);
    EndDrawing();
    }
  CloseWindow();
}

void OpenLeaderboard() {
  LEADERBOARD_STRUCT leaderboard_struct[NUMERO_JOGADORES];
  ReadBinaryFile(leaderboard_struct);
  PrintLeaderboard(leaderboard_struct);
}

int main() {
  int user_option = 0;
  while (user_option != EXIT_RETURN) {
    user_option = GameMenu();
    if (IsKeyPressed(KEY_ESCAPE))
      return 0;
    if (user_option == PLAY_RETURN)
      return 0; // FOR NOW ONLY
    if (user_option == LEADERBOARD_RETURN)
      OpenLeaderboard();
  }    
  return 0; 
}