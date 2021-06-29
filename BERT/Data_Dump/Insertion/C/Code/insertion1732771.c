#include<stdio.h>
#define N 100

int main(){
  int i,j,k,array[N],n,key;

   scanf("%d",&n);
  
  for(j=0;j<n;j++)scanf("%d",&array[j]);
  
  for(i=0;i<n-1;i++)printf("%d ",array[i]);
  printf("%d\n",array[i]);

  for(i=1;i<n;i++){
    key=array[i];
    j=i-1;
    while(j>=0 && array[j]>key){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=key;
    for(k=0;k<n-1;k++){
      printf("%d",array[k]);
      printf(" ");
    }
    printf("%d\n",array[k]);
  }
  
  return 0;
}
