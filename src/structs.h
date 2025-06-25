#include "raylib.h"

typedef struct MegamanStruct {
  Vector2 position;
  Vector2 velocity;
  Texture2D idle;
  Texture2D shooting_idle;
  Texture2D shooting_running;
  Texture2D running;
  Texture2D jumping;
  Texture2D death;
  int lives;
  int speed;
  int gravity;
} MEGAMAN;

typedef struct EnemyStruct {
  Vector2 postion;
  Texture2D texture;
} ENEMY;

typedef struct BoxStruct {
  Vector2 position;
  Texture2D texture;
} BOX;

typedef struct SpikeStruct {
  Vector2 position;
  Texture2D texture;
} SPIKE;

typedef struct BackgroundStruct {
  Texture2D texture;
} BACKGROUND;

typedef struct TiroStruct {
  Vector2 positon;
  Vector2 velocity;
  Texture2D texture;
} TIRO;