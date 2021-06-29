#include<stdio.h>
int main(){
  int i,j,K,n,t,count=0,mini;
  scanf("%d",&K);
  int N[K];
  for(i=0;i<K;i++)
    scanf("%d",&N[i]);
  for(i=0;i<K-1;i++){
    mini=i;
    for(j=i;j<K;j++){
      if(N[j]<N[mini]){
	mini=j;
      }
    }
    int t=N[i];
    N[i]=N[mini];
    N[mini]=t;
    if(mini!=i)
      count++;
  }
  for(n=0;n<K;n++){
    if(n == K-1)
      printf("%d",N[n]);
    else printf("%d ",N[n]);
  }
  printf("\n%d\n",count);
  return 0;
}
