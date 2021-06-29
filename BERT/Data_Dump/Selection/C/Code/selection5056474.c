#include<stdio.h>

int swap(int *,int *);

int main(void)
{
  
  int i,j,min,length,count,A[100];
  
  //値を入力
  scanf("%d",&length);
  for(i=0; i<length; i++){
    scanf("%d",&A[i]);
  }

  
  for(i=0; i<length; i++){
    min = i;
    
    //未ソート部分の最小値を求める
    for(j=i+1; j<length; j++){  
      if(A[j] < A[min]){
	min = j;	
      }
    }
    
    //最小値が未ソート部分の先頭でないとき、選択ソートを行う
    if(min != i){ 
      count = swap(&A[i],&A[min]);
    }
  }
  
  //値を出力
  for(i=0; i<length-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[length-1]);
  printf("%d\n",count);
  
  return 0;
}


//値を入れ替えて回数を数える関数
int swap(int *x,int *y)
{
  
  int temp;
  static int count=0;
  
  temp = *x;
  *x = *y;
  *y = temp;
  
  count++;
  
  return count;
}

