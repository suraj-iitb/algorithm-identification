#include<stdio.h>
#include<stdlib.h>

int sellectionSort(int *, int);

int main(){
  int n,i,count;
  int *a;

  scanf("%d",&n);
  if(n < 1 || 100 < n)exit(0);

  a = malloc(n*sizeof(int));
  
  for(i = 0; i < n; i++){
    scanf("%d",a+i);
    if(*(a+i) < 0 || 100 < *(a+i))exit(1);
  }

  count = sellectionSort(a,n);

  printf("%d",*a);
  for(i = 1; i < n; i++){
    printf(" %d",*(a+i));
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

int sellectionSort(int *a,int n){
  int count,i,j,min,v;

  count = 0;
  
  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(a[j] < a[min]){
        min = j;
      }
    }
    v = a[i];
    a[i] = a[min];
    a[min] = v;
    if(i != min)count++;
  }

  return count;
}

