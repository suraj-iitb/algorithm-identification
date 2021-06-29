#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define GRAY 1
#define BLUCK 2

void DepthFirstSearch();
void visit(int);

int matrix[200][200];
int color[200];
int SumVirtex;
int Time;
int FirstVirtexTime[200];
int LastVirtexTime[200];

/*ここからがmain関数*/
int main()
{
  int i, j, VirtexNum, ConnectSum, connect;

  scanf("%d",&SumVirtex);

  for(i = 1; i <= SumVirtex; i++){
    scanf("%d",&VirtexNum);
    scanf("%d",&ConnectSum);
    for(j = 1; j <= ConnectSum; j++){
      scanf("%d",&connect);
      matrix[i][connect] = matrix[i][connect] + 1;
    }
  }

  DepthFirstSearch();

  for(i = 1; i <= SumVirtex; i++){
    printf("%d %d %d\n", i, FirstVirtexTime[i], LastVirtexTime[i]);
  }
  return 0;
}

/*ここからがvisit関数*/
void visit(int i)
{
  int j;

  color[i] = GRAY;

  FirstVirtexTime[i] = ++Time;

  for(j = 1; j <= SumVirtex; j++){
    if(color[j] == WHITE && matrix[i][j] == 1){
      visit(j);
    }
  }
  color[i] = BLUCK;
  LastVirtexTime[i] = ++Time;
}

/*ここからがDepthFirstSearch関数*/
void DepthFirstSearch()
{
  int i;
  
  Time = 0;
 
  for(i = 1; i <= SumVirtex; i++)
    color[i] = WHITE;

  for(i =1 ; i <= SumVirtex; i++){
    if(color[i] == WHITE)
      visit(i);
  }
}

