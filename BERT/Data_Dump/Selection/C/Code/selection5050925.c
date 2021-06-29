#include<stdio.h>
int main(){
  int N,A[100],i,j,k,min,key,cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(A[j]<A[min]){
        min=j;
      }
    }
    key=A[i];
    A[i]=A[min];
    A[min]=key;
    if(A[i]!=A[min])cnt++;
  }
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",cnt);

  return 0;
}

