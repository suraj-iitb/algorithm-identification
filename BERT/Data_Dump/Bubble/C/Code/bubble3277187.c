#include <stdio.h>

int main(){

  int bubblesort[100],N,i,j,exist=1,count=0,rep;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&bubblesort[i]);
  
  }

  while(exist==1){
    exist=0;
    for(j=N-1;j>=1;j--){
     
      if(bubblesort[j]<bubblesort[j-1]){
	rep=bubblesort[j-1];
	bubblesort[j-1]=bubblesort[j];
	bubblesort[j]=rep;
	exist=1;
	count++;
      }
    }
  }

  for(i=0;i<N;i++){

    if(i!=N-1)printf("%d ",bubblesort[i]);
    else printf("%d",bubblesort[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

