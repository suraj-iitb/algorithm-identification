#include<stdio.h>
#define N 100

int main(){
  int array[N];
  int n,minj;
  int i,j;
  int count=0;
  int temp;

  /* Input */
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(array[j]<array[minj]){
	minj=j;
      }
    }
    temp=array[i];
    array[i]=array[minj];
    array[minj]=temp;
    if(i!=minj) count++;
  }

  /* Output */
  for(i=0;i<n-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[n-1]);
  printf("%d\n",count);
  
  return 0;
}

