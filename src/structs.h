#ifndef structs.h
#define structs.h

typedef struct
{
  Vector2 position;
  Vector2 velocity;
  Texture2D texture;
  int lives;
  int speed;
  int gravity;
} MEGAMAN;

typedef struct ENEMYSTRUCT
{
  Vector2 postion;
  Texture2D texture;
} ENEMY;

typedef struct BOXSTRUCT
{
  Vector2 position;
  Texture2D texture;
} BOX;

typedef struct SPIKESTRUCT
{
  Vector2 position;
  Texture2D texture;
} SPIKE;

typedef struct BACKGROUNDSTRUCT
{
  Texture2D texture;
}

typedef struct TIROSTRUCT
{
  Vector2 positon;
  Vector2 velocity;
  Texture2D texture;
}

#endif