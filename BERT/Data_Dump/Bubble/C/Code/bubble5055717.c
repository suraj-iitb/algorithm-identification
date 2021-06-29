#include<stdio.h>

int swap(int *,int *);

int main(void)
{
  
  int i,j,length,count=0,N[100]={};
  
  //データ入力
  scanf("%d",&length);
  for(i=0; i<length; i++){
    scanf("%d",&N[i]);
  }
  
  //入力されたデータを元に実行
  for(i=0; i<length-1;i++){
    for(j=length-1; j>i; j--){
      if(N[j]<N[j-1]){
	count = swap(&N[j],&N[j-1]);
      }	
    }
    printf("%d ",N[i]);
  }

  printf("%d\n",N[length-1]);
  printf("%d\n",count);
  
  return 0;
}

//値を入れ替え、回数を数える関数
int swap(int *x,int *y){
  
  int temp;
  static int count=0; 
  
  temp = *x;
  *x = *y;
  *y = temp;
  
  count++;
  
  return count;
}















  

