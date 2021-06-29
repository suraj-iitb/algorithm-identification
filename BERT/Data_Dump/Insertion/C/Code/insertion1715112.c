#include <stdio.h>
  
void print_array(int *array,int n){
  int i;
  
  for(i=0;i<n-1;i++)  printf("%d ",array[i]);
  printf("%d\n",array[n-1]);
}
  
int main(void){
  int i,j,v,n,array[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)  scanf("%d",&array[i]);  
  for(i=0;i<n;i++){
    v=array[i];
    j=i-1;
    while(j>=0 && array[j]>v){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=v;
    print_array(array,n);
  }
  
  return 0;
}
