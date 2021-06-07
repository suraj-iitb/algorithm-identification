#include<stdio.h>
#define MAX 10000

int main(void){
  int S[MAX],T[MAX],n,q,count=0,i,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j] == T[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;  
}
