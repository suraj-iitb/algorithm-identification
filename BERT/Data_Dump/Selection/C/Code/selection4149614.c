#include<stdio.h>
#include<stdlib.h>
#define A 100

int selectionSort(int *, int);

int main(){

  int a[A],n,i,count;

  scanf("%d",&n);
  
  if(n < 1 && n >100)exit(2);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }
  count = selectionSort(a,n);
  
  for(i = 0 ; i < n-1 ; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

int selectionSort(int *a,int n){
  int i,j;
  int num,minj,count=0;
    
  for(i = 0; i <= n-1  ; i++){
    minj = i;
    for(j = i; j <= n -1; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(a[i] != a[minj]){
    num = a[minj];
    a[minj] = a[i];
    a[i] = num;
    count++;
    }
  }
  return count;
}
  

