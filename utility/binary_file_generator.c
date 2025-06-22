#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nomeJog[12];
  int pontuacao;
} POSICOES;

int main()
{
  POSICOES leaderboard [5] =
  {
    {"MARCELO", 850},
    {"GABRIEL", 800},
    {"FRANCISCO", 600},
    {"ISMAEL", 500},
    {"ADRIANA", 200}
  };
  
  FILE *fp;
  fp = fopen("top_scores.bin", "wb");

  if (fp != NULL)
  {
    if(fwrite(leaderboard, sizeof(POSICOES), 5, fp) != 5)
        printf("ERRO NA LEITURA!");
    else
    printf("ARQUIVO LIDO COM SUCESSO!");
  }
  fclose(fp);

  return 0;
}
