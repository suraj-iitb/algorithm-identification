#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
int main(){//kが要素の最大値                                                 
  unsigned short *A,*B;
  int N,C[VMAX+1],i,j,k=0;
  scanf("%d",&N);
  A = malloc(sizeof(short)*N+1);
  B = malloc(sizeof(short)*N+1);
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
    if(A[i]>k)
      k=A[i];//最大値求めた                                                  
  }
  for(i=0;i<=k;i++)
    C[i]=0;//初期化                                                          

  for(j=1;j<=N;j++)
    C[A[j]]=C[A[j]]+1;//A[i]の出現数を記録する                               

  for(i=1;i<=k;i++)
    C[i]=C[i]+C[i-1];//前の数を足していく                                    
  for(j=N;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
  for(i=1;i<=N;i++){
    printf("%d",B[i]);
    if(i==N){
      printf("\n");
      break;
    }
    printf(" ");
  }
  return 0;
}




