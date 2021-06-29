#include<stdio.h>


int main(){
  int i,j=0,s,v,N;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
     }
  for(i=1;i<=N;i++){
    v=A[i];
    j=i-1;
     for(s=0;s<=N-1;s++){
      if(s<N-1)
      printf("%d ",A[s]);
      else printf("%d",A[s]);
    }
    printf("\n");
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }

  return 0;
}

