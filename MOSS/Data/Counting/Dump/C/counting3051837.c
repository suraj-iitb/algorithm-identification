#include <stdio.h>
void CountingSort(int *,int *,int );

int n;
int tA[10000000],tB[10000000];

int main(){
  int i,max=0;

  scanf("%d",&n);
  tA[0]=0;
  for(i=1;i<=n;i++){
    scanf("%d",&tA[i]);

    if(max<tA[i])max=tA[i];

  }

  for(i=1;i<=n;i++){
    tB[i]=0;
  }
  CountingSort(tA,tB,max);


  return 0;
}


void CountingSort(int A[],int B[],int k){
  int i,j;
  int C[100000];

  for (i = 0 ;i<=k;i++){
    C[i] = 0;
  }

  
  for( j = 1 ;j<= n;j++){

    C[A[j]]++;
  }


   
  for (i = 1 ;i<= k;i++){

    C[i] = C[i] + C[i-1];
  }

  for( j = n ;j>= 1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    if(i>1){
      printf(" ");
    }
    
    printf("%d",B[i]);
  }
  printf("\n");
}

