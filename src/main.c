#include <stdio.h> //library for printing
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include "structs.h"

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
    DrawTexture(title_texture, title_texture_pos_x, 100, RAYWHITE);
    Rectangle play_button_rec = (Rectangle) {
      play_button_pos_x, 280, play_button_width, 30
    };
    Rectangle leaderboard_button_rec = (Rectangle) {
      leaderboard_button_pos_x, 360, leaderboard_button_width, 30
    };
    Rectangle exit_button_rec = (Rectangle) {
      exit_button_pos_x, 440, exit_button_width, 30
    };
    if (CheckCollisionPointRec(GetMousePosition(), play_button_rec)) {
      DrawText("PLAY", play_button_pos_x, 280, 30, LIGHTGRAY);
    } else {
      DrawText("PLAY", play_button_pos_x, 280, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), leaderboard_button_rec)) {
      DrawText("LEADERBOARD", leaderboard_button_pos_x, 360, 30, LIGHTGRAY);
    } else {
      DrawText("LEADERBOARD", leaderboard_button_pos_x, 360, 30, RAYWHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), exit_button_rec)) {
      DrawText("EXIT", exit_button_pos_x, 440, 30, LIGHTGRAY);
    } else {
      DrawText("EXIT", exit_button_pos_x, 440, 30, RAYWHITE);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (CheckCollisionPointRec(GetMousePosition(), play_button_rec))
        return PLAY_RETURN;
      if (CheckCollisionPointRec(GetMousePosition(), leaderboard_button_rec))
        return LEADERBOARD_RETURN;
      if (CheckCollisionPointRec(GetMousePosition(), exit_button_rec))
        return EXIT_RETURN;
		}
    EndDrawing();
  }
  UnloadTexture(title_texture);
  CloseWindow();
  return 0;
}

void ReadBinaryFile(LEADERBOARD_STRUCT leaderboard_struct[NUMERO_JOG]) {
  FILE* leaderboard_file;
  leaderboard_file = fopen("scores.bin", "rb");
  fread(leaderboard_struct, sizeof(LEADERBOARD_STRUCT), NUMERO_JOG, leaderboard_file);
  fclose(leaderboard_file);
}

void PrintLeaderboard(LEADERBOARD_STRUCT leaderboard_struct[NUMERO_JOG]) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LEADERBOARD");
	SetTargetFPS(60);
  while(!WindowShouldClose()) {
    for (int i = 0; i < 5; i++) {
      int player_name_width = MeasureText(leaderboard_struct[i].player_name, 10);
      int player_name_pos_x = SCREEN_WIDTH / 2 - player_name_width;
      char current_player_name[12];
      strcpy(current_player_name, leaderboard_struct[i].player_name);
      int current_score = leaderboard_struct[i].score;
      DrawText(current_player_name, player_name_pos_x, 100, 10, WHITE);
      DrawText(TextFormat("%i", current_score), SCREEN_WIDTH / 2 + 20, 100, 10, WHITE);
      EndDrawing();
    }
  }
    CloseWindow();
}

void OpenLeaderboard() {
  LEADERBOARD_STRUCT leaderboard_struct[NUMERO_JOG];
  ReadBinaryFile(leaderboard_struct);
  PrintLeaderboard(leaderboard_struct);
}

//FIX TABS OPENING OVER ONE ANOTHER
int main() {
  int user_option;
  user_option = GameMenu();
  if (user_option == EXIT_RETURN)
    return 0;
  if (user_option == LEADERBOARD_RETURN)
    OpenLeaderboard();
}