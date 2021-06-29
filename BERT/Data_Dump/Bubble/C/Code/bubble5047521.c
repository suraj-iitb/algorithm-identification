#include<stdio.h>
int main(){
  int i,j,exch,s=0,N,frag=1,A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(frag==1){
    frag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
        exch=A[j];
        A[j]=A[j-1];
        A[j-1]=exch;
        frag=1;
        s++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n%d\n",s);
}

