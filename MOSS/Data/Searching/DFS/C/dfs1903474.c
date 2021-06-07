#include<stdio.h>
#define MAX 100
void Graph(int **);
void Clear();
void Jugde(int);

int A[MAX][MAX],JDGE[MAX],DWN[MAX],FLT[MAX];
int *B[MAX];
int N;
int time = 0;
int i,j;

int main(){

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      A[i][j] = 0;
    }
  }

  for(i = 0; i < N; i++){
    B[i] = A[i];
  }

  Graph(B);

  Clear();
  

  for(i = 0; i < N; i++){
    printf("%d %d %d\n",i+1,DWN[i],FLT[i]);
  }

  return 0;
}


void Graph(int **A){
  int u,k,v;

  for(i = 0; i < N; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j< k; j++){
      scanf("%d",&v);
      v--;
      A[u][v] = 1;
    }
  }
}

void Clear(){
  int a;
  for(a = 0; a < N; a++){
    JDGE[a] = 0;
  }

  for(a = 0; a < N; a++){
    if(JDGE[a] == 0) Judge(a);
  }

}

void Judge(int a){
  int b;
  JDGE[a] = 1;
  DWN[a] = ++time;
  for(b = 0; b < N; b++){
    if(A[a][b] == 0) continue;
    if(JDGE[b] == 0) Judge(b);
  }
  JDGE[a] = 2;
  FLT[a] = ++time;
}
