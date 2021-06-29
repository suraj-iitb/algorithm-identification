#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *,int);
int cnt=0;

int main(){
  int i,n,array[100];
  scanf("%d",&n);
  if(n<1 || n>100) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  selectionSort(array,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

void selectionSort(int *arr,int n){
  int i,j,tmp,min;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=n-1;j>i;j--){
      if(arr[min] >= arr[j]) min=j;
    }
    if(arr[min]!=arr[i]){
      tmp=arr[min];
      arr[min]=arr[i];
      arr[i]=tmp;
      cnt++;
    }
  }
}

