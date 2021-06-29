#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,*selection;
  int i,j,tmp,min,k,count=0,flag=0;
  scanf("%d",&N);
  if(N>=1&&N<=100){//Nの条件は問題文に応じて変更する
    selection=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
      scanf("%d",&selection[i]);
      if(selection[i]<0||selection[i]>100){
	exit(1);
      }
    }
    for(i=0;i<N-1;i++){
      min=i;//配列の先頭を最小値とする
      flag=0;
      for(j=i;j<N;j++){//比較ループ
	if(selection[j]<selection[min]){//昇順に並べるから
	  min=j;//最小値を持つ要素を更新
	  flag=1;
	}
      }
      if(flag){
	count++;
      tmp=selection[i];
      selection[i]=selection[min];
      selection[min]=tmp;
      }
    }
    for(k=0;k<N;k++){
      if(k!=N-1)printf("%d ",selection[k]);
      else printf("%d",selection[k]);
    }
    printf("\n%d\n",count);
    
  }
  return 0;
}

