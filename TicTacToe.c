#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// compile cmd: gcc -g -o TicTacToe.exe ./TicTacToe.c
// run cmd: ./TicTacToe.exe
void printBoard(char[3][3], int, int);
bool checkIfWin();

int main()
{
  char boardPosition[3][3] = {{'e', 'e', 'e'}, {'e', 'e', 'e'}, {'e', 'e', 'e'}};
  bool p1Turn = true;
  printf("************\n");
  printf("Tic Tac Toe\n");
  printf("************\n\n");

  do
  {
    char *turn = p1Turn == true ? "Player 1's Turn\n" : "Player 2's Turn\n";
    int row;
    int col;
    printf("%s", turn);
    printf("Row:");
    scanf("%d", &row);
    while (row < 1 || row > 3)
    {
      printf("Please enter a row between 1 and 3.\nRow:");
      scanf("%d", &row);
    }
    printf("Column:");
    scanf("%d", &col);
    while (col < 1 || col > 3)
    {
      printf("Please enter a column between 1 and 3.\nColumn:");
      scanf("%d", &col);
    }
    while (boardPosition[row - 1][col - 1] != 'e')
    {
      printf("\nPlease choose a spot another player isn't on.\n");
      printf("%s", turn);
      printf("Row:");
      scanf("%d", &row);
      while (row < 1 || row > 3)
      {
        printf("Please enter a row between 1 and 3.\nRow:");
        scanf("%d", &row);
      }
      printf("Column:");
      scanf("%d", &col);
      while (col < 1 || col > 3)
      {
        printf("Please enter a column between 1 and 3.\nColumn:");
        scanf("%d", &col);
      }
    }
    boardPosition[row - 1][col - 1] = (p1Turn == true ? 'x' : 'o');
    printBoard(boardPosition, 3, 3);
    p1Turn = !p1Turn;
  } while (checkIfWin(boardPosition) == false);

  if (p1Turn)
  {
    printf("Player 2 Won!!!!");
  }
  else
  {
    printf("Player 1 Won!!!!");
  }
  return 0;
}

void printBoard(char boardPosition[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (j == cols - 1)
      {
        printf("  %-2c", boardPosition[i][j]);
      }
      else
      {
        printf("  %-2c|", boardPosition[i][j]);
      }
    }
    if (i == rows - 1)
    {
      printf("\n");
    }
    else
    {
      printf("\n---------------\n");
    }
  }
  printf("\n");
}

bool checkIfWin(char boardPosition[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    if (boardPosition[i][0] == boardPosition[i][1] && boardPosition[i][1] == boardPosition[i][2] && boardPosition[i][0] != 'e')
    {
      return true;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (boardPosition[0][i] == boardPosition[1][i] && boardPosition[1][i] == boardPosition[2][i] && boardPosition[0][i] != 'e')
    {
      return true;
    }
  }

  if (boardPosition[0][0] == boardPosition[1][1] && boardPosition[1][1] == boardPosition[2][2] && boardPosition[0][0] != 'e')
  {
    return true;
  }
  if (boardPosition[0][2] == boardPosition[1][1] && boardPosition[1][1] == boardPosition[2][0] && boardPosition[0][2] != 'e')
  {
    return true;
  }

  return false;
}