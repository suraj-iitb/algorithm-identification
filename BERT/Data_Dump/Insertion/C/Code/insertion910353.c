#include<stdio.h>
int main(){
  int i,key,j,K,n;
  scanf("%d",&K);
  int N[K];
  for(i=0;i<K;i++)
    scanf("%d",&N[i]);
  for(n=0;n<K;n++){
    if(n == K-1)
      printf("%d",N[n]);
    else printf("%d ",N[n]);
  }
  printf("\n");
  for(i=1;i<K;i++){
    key = N[i];
    j = i - 1;
    while((j >= 0) && (N[j] > key)){
      N[j + 1] = N[j];
      j--;
    }
    N[j + 1] = key;
    for(n=0;n<K;n++){
      if(n == K-1)
	printf("%d",N[n]);
      else printf("%d ",N[n]);
    }
    printf("\n");
  }
  return 0;
}
