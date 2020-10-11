#include<stdio.h>
int main(void){
  int i,j;
  int len,key;
  int array[100];
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&array[i]);
  }
  for(i=0;i<len;i++){
    key=array[i];
    for(j=i-1;j>0,array[j]>key;j--){
      array[j+1]=array[j];
	}
    array[j+1]=key;
    for(j=0;j<len;j++){
      if(j>0)printf(" ");
      printf("%d",array[j]);
    }
      printf("\n");
  }
  return 0;
}
