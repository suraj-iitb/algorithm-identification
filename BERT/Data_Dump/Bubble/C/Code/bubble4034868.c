#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *,int);
int cnt=0;

int main(){
  int i,n,array[100];
  scanf("%d",&n);
  if(n<1 || n>100) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  bubbleSort(array,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

void bubbleSort(int *arr,int n){
  int i,j,tmp;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(arr[j-1] > arr[j]){
	tmp=arr[j-1];
	arr[j-1]=arr[j];
	arr[j]=tmp;
	cnt++;
      }
    }
  }
}

