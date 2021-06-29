#include<stdio.h>

int main(){
  int i,j,key,count=0,data1,data2,array1[10001],array2[500];

  scanf("%d",&data1);
  for(i=0;i<data1;i++)scanf("%d",&array1[i]);
  scanf("%d",&data2);
  for(i=0;i<data2;i++){
    scanf("%d",&key);
      //for(i=0;i<data2;i++){
      // key=array[2];
    j=0;
    array1[data1]=key;
    while(array1[j] != key)j++;
    if(j != data1)count++;
  }
  printf("%d\n",count);
  return 0;
}
   
