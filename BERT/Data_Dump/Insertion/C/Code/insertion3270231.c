#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *,int);
int main(){
  int n,*array,i;
  scanf("%d",&n);
  array = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  insertionSort(array,n);
  
  return 0;
}

void insertionSort(int *array,int n){
  int i,j,l,data;
  for(j=0;j<n;j++){
    printf("%d",array[j]);
    if(j != n-1){
      printf(" ");
    }
  }
  printf("\n");
  for(i=1;i<n;i++){
    data = array[i];
    j = i-1;
    while(j>=0 && array[j]>data){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = data;
    for(l=0;l<n;l++){
      printf("%d",array[l]);
      if(l != n-1){
	printf(" ");
      }
    }
      printf("\n");
  }
}

