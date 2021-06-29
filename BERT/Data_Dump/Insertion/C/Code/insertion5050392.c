#include<stdio.h>

int main(void)
{
  
  int i,j,k,length,key,A[100]={};
  
  //データ入力
  scanf("%d",&length);
  for(i=0; i<length; i++){
    scanf("%d",&A[i]);
  }
  
  
  
  //入力内容の出力
  for(i=0; i<length-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[length-1]);
  printf("\n");
  
  
  //keyがA[1]の時
  if(length>1){
    key = A[1];
    if(key<A[0]){
      A[1] = A[0];
      A[0] = key;
    }
    for(i=0; i<length-1; i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[length-1]);
    printf("\n");
  }
  
  //keyがA[2]-A[5]の時
  if(length>2){
    for(i=0; i<length-2; i++){
      key = A[i+2];
      j = i+1;
      
      while(j>=0 && A[j]>key){
	A[j+1] = A[j];
	j--;
      }
      A[j+1] = key;
      
      for(k=0; k<length-1; k++){
	printf("%d ",A[k]);
      }
      printf("%d",A[length-1]);
      printf("\n"); 
    }
  }
  
  return 0;
}


