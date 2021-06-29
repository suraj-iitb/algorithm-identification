#include<stdio.h>

int main(){
  int i,mini,k,N,A[100],c=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    mini = i;
    for(k=i;k<N;k++){
      if(A[k]<A[mini]){
	mini=k;
      }
    }
    k=A[i];
    A[i]=A[mini];
    A[mini]=k;
    if(i!=mini)c++;//i=cの場合交換は無い
  }
  for(k=0;k<N;k++)if(k!=N-1)printf("%d ",A[k]);else printf("%d\n",A[k]);
  printf("%d\n",c);
  return 0;
}

