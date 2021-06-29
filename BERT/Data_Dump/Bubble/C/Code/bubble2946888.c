#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,*bubble;
  int i,j,flag,tmp,k,count=0;
  scanf("%d",&N);
  if(N>=1&&N<=100){//Nの条件は問題文に応じて変更する
    bubble=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
      scanf("%d",&bubble[i]);
      if(bubble[i]<0||bubble[i]>100){
	exit(1);
      }
    }
    flag=1;
    while(flag){
      flag=0;
      i=0;
      for(j=N-1;j>=i;j--){
	if(bubble[j-1]>bubble[j]){
	  tmp=bubble[j-1];
	  bubble[j-1]=bubble[j];
	  bubble[j]=tmp;
	  flag=1;
	  count++;
	}
      }
      i++;
    }
    for(k=0;k<N;k++){
      if(k!=N-1)printf("%d ",bubble[k]);
      else printf("%d",bubble[k]);
    }
    printf("\n");
    printf("%d\n",count);
  }

  return 0;
}


