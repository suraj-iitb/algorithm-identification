#include <stdio.h>
#define H 101
int A[H][H], K[H], P[H];

void sao(int z, int v){
  int i;
  P[z] = v;
  for(i=1; i<=K[z]; i++){
    if(P[A[z][i]] > v)
      sao(A[z][i], v+1);
  }
}

int main(){
  int o, i, j, h;
  
  scanf("%d", &h);
  for(i=1; i<=h; i++){
    P[i] = 10000;
    for(j=1; j<=h; j++)
      A[i][j] = 0;
  }
  
  for(i=1; i<=h; i++){
    scanf("%d", &o);
    scanf("%d", &K[o]);
    for(j=1; j<=K[o]; j++)
      scanf("%d", &A[o][j]);
  }
  sao(1,0);
  for(i=1; i<=h; i++){
    if(P[i] == 10000)
      P[i] = -1;
    printf("%d %d\n", i, P[i]);
  }
  return 0;
}
  

