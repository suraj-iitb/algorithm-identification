#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BRACK 2

int **matrix;
int *color;
int *disc;
int *fin;
int n;
int time;

void dps(void);
void visit(int);


int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  
  color = malloc((n+1) * sizeof(int));
  disc = malloc((n+1) * sizeof(int));
  fin = malloc((n+1) * sizeof(int));
  
  matrix = malloc((n+1) * sizeof(int *));
  for(i=0;i<n+1;i++) matrix[i] = malloc((n+1) * sizeof(int));
  
  
  for(i=1;i<n+1;i++)
    for(j=1;j<n+1;j++)
      matrix[i][j] = 0;
  
  
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      matrix[u][v] = 1;
    }
  }
  
  dps();

  for(i=1;i<n+1;i++) printf("%d %d %d\n",i,disc[i],fin[i]);

  free(matrix);

  return 0;
}

void dps(){
  int i;

  for(i=1;i<n+1;i++) color[i] = WHITE;
  time = 0;

  for(i=1;i<n+1;i++)
    if(color[i] == WHITE ) visit(i);
}

void visit(int u){
  int i;

  color[u] = GRAY;
  disc[u] = ++time;

  for(i=1;i<n+1;i++)
    if(matrix[u][i] == 1 && color[i] ==  WHITE ) visit(i);

  color[u] = BRACK;
  fin[u] = ++time;
}
