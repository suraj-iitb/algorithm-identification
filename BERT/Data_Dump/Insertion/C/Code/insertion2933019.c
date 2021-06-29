#include<stdio.h>
int A[1000];

int main(){
  int i,j,v,N,a;
  scanf("%d",&N);//数列の長さ//
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<N;i++){
    for(a=0;a<N-1;a++){
      printf("%d ",A[a]);
    }
    printf("%d\n",A[N-1]);
    v=A[i];
    j = i-1;

    while(j >= 0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    
    }
      A[j+1] = v;   
  }

  for(a=0;a<N-1;a++){
    printf("%d ",A[a]);
  } 
  printf("%d\n",A[N-1]);

  return 0;
}

