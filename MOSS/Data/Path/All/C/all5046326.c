#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll** vector(int y,int x){
  ll** res;
  res=(ll**)malloc(sizeof(ll*) * y);
  for(int i=0;i<y;i++){
    res[i]=(ll*)malloc(sizeof(ll) * x);
  }
  return res;
}

int main (){
  int i=0, j=0, k=0, x, y, z, w;
  scanf("%d %d", &x, &y);
  ll **A=vector(x,x);
  
  
  for (i = 0; i < x; i++){
    for (j = 0; j < x; j++){
      A[i][j] = 20000000001;
    }
  }
  
  for (i = 0; i < y; i++){
    scanf(" %d %d", &z, &w);
    scanf(" %lld", &A[z][w]);
  }

  /*for (i = 0; i < x; i++){
    for (j = 0; j < x; j++){
      if (A[i][j] != 20000000001){
	printf("%d",A[i][j]);
      } else {
	printf("INF");
      }
      if (j != x-1) printf(" ");
    }
    printf("\n");
    }*/

  for (i = 0; i < x; i++){
    for (j = 0; j < x; j++){
      if (A[i][j]+A[j][i] < 0){
	printf("NEGATIVE CYCLE\n");
	return 0;
      }
    }
  }

  for (i = 0; i < x; i++){
    A[i][i] = 0;
  }

  for (k = 0; k < x; k++){
    for (i = 0; i < x; i++){
      for (j = 0; j < x; j++){
	if (A[i][k] != 20000000001 && A[k][j] != 20000000001){ 
	  if (A[i][j] > A[i][k]+A[k][j]) A[i][j] = A[i][k]+A[k][j];
	}
      }
    }
  }

  for (i = 0; i < x; i++){
    if(A[i][i] < 0){
      printf("NEGATIVE CYCLE\n");
      return 0;
    }
  }

  for (i = 0; i < x; i++){
    for (j = 0; j < x; j++){
      if (A[i][j] != 20000000001){
	printf("%d",A[i][j]);
      } else {
	printf("INF");
      }
      if (j != x-1) printf(" ");
    }
    printf("\n");
  }
  
  return 0;
}

