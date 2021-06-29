#include <stdio.h>

int main(){

  int i,j,N,selsort[100],min,rep,count=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){

    scanf("%d",&selsort[i]);
  
  }

  for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
      if(selsort[j]<selsort[min]){
	min=j;

      }
    }
    if(selsort[i]!=selsort[min]) count++;
    rep=selsort[i];
    selsort[i]=selsort[min];
    selsort[min]=rep;
  }
  
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",selsort[i]);
    else printf("%d\n",selsort[i]);

  }
  printf("%d\n",count);
  return 0;
}

