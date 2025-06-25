#include <stdio.h> // library for printing
#include <math.h>
#include <stdbool.h>
#include "raylib.h"
#include "constants.h"
#include "prototypes.h"
#include "structs.h"

int main() {
  int user_option;
  user_option = GameMenu();
  return 0;
}

int GameMenu() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MENU");
  Texture2D title = LoadTexture("C:\\Users\\ismul\\OneDrive\\Desktop\\INFMAN remake\\sprites\\inf_man.png");
  SetTargetFPS(60);
  
  float title_button_pos_x = SCREEN_WIDTH / 2 - 426 / 2;
  float play_button_pos_x = SCREEN_WIDTH / 2.0f -
                            MeasureText("PLAY", 30) / 2.0f;
  float leaderboard_button_pos_x = SCREEN_WIDTH / 2.0f - 
                                   MeasureText("LEADERBOARD", 30) / 2.0f;
  float exit_button_pos_x = SCREEN_WIDTH / 2.0f -
                            MeasureText("EXIT", 30) / 2.0f;
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawTexture(title, title_button_pos_x, 100, RAYWHITE);
    DrawText("PLAY", play_button_pos_x,
             280, 30, RAYWHITE);
    DrawText("LEADERBOARD", leaderboard_button_pos_x,
             360, 30, RAYWHITE);
    DrawText("EXIT", exit_button_pos_x,
             440, 30, RAYWHITE);
    Rectangle play_button_rec = (Rectangle) {
			play_button_pos_x,
			280, MeasureText("PLAY", 30), 30};
    Rectangle leaderboard_button_rec = (Rectangle) {
			leaderboard_button_pos_x,
			360, MeasureText("LEADERBOARD", 30), 30};
    Rectangle exit_button_rec = (Rectangle) {
			exit_button_pos_x,
			440, MeasureText("EXIT", 30), 30};
      
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (CheckCollisionPointRec(GetMousePosition(), play_button_rec))
				return PLAY;
			if (CheckCollisionPointRec(GetMousePosition(), leaderboard_button_rec))
				return LEADERBOARD;
			if (CheckCollisionPointRec(GetMousePosition(), exit_button_rec))
				return EXIT;
		}
  }
}




