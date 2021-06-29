#include<stdio.h>

#define One -1
#define Two -2
#define Three -3


int A[101][101], B[101], C[101], D[101];
int n; 
int time;

void DepthFirstSearch(int m){

  int i;

  //printf("ok\n");
  D[m] = Two;
  time++;
  B[m] = time;

  for(i = 0;i <= n;i++){
    if(A[m][i] && D[i] == Three){
      DepthFirstSearch(i);
    }
  }
  D[m] = One;
  C[m] = ++time;
}

void DepthFirst(int l){
  int i;
  for(i = 0;i < l;i++){
    if(D[i] == Three){
      //printf("ok\n");
      DepthFirstSearch(i);
    }
  }
}

int main(){

  int i,j;
  int id,d,f;

  scanf("%d",&n);

  for(i = 0; i < 100;i++){
    for(j = 0;j < 100;j++){
      A[i][j] = 0;
    }
    D[i] = Three;
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&id,&d);
    for(j = 0;j < d;j++){
      scanf("%d",&f);
      A[i][f-1] = 1;
    }
  }

  DepthFirst(n);

  for(i = 0;i < n;i++){
    printf("%d %d %d\n",i+1,B[i],C[i]);
  }
  return 0;
}
