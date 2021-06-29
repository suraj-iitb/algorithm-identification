#include<stdio.h>
int main(){
  int N,h,i,j,k,m,v,A[100];
  scanf("%d",&N);
  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }
  for(h=0;h<N;h++){
    printf("%d",A[h]);
    if(h<N-1){
      printf(" ");
    }
  }
  printf("\n");
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(m=0;m<N;m++){
      printf("%d",A[m]);
      if(m<N-1){
        printf(" ");
      }
    }
    printf("\n");
  }
}

