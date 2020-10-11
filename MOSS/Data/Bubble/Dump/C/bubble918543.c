#include<stdio.h>
int main(){
  int i,j,K,n,t,count=0;
  scanf("%d",&K);
  int N[K];
  for(i=0;i<K;i++)
    scanf("%d",&N[i]);
    for(i=0;i<K-1;i++){
  for(j=K-1;i<j;j--){
      if(N[j]<N[j-1]){
	int t=N[j];
	N[j]=N[j-1];
	N[j-1]=t;
	count++;
      }
    }
  }
  for(n=0;n<K;n++){
    if(n == K-1)
      printf("%d",N[n]);
    else printf("%d ",N[n]);
  }
  printf("\n%d\n",count);
  return 0;
}
