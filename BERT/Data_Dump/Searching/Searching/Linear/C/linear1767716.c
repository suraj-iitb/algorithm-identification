#include<stdio.h>
#define N 10000

int main(){

  int i,j,n,k,count=0;
  int S[N],T[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&k);

  for(i=0;i<k;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<k;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
