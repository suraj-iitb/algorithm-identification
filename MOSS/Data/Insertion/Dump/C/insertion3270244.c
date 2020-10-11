#include<stdio.h>

void insertionSort(int*, int[]);

int main(){
  int i,j,n,v,k;
  int a[1000];

  insertionSort(&n,a);

  for(k = 0; k < n; k++){
    if(k == n - 1)  printf("%d",a[k]);
    else printf("%d ",a[k]);
  }
  printf("\n");

  for(i = 1; i <= n - 1; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
   for(k = 0; k < n; k++){
     if(k == n - 1)  printf("%d",a[k]);
     else printf("%d ",a[k]);
       }
       printf("\n");
  }
  
  return 0;
}

void insertionSort(int *n, int a[]){
  scanf("%d",n);
  for(int i = 0; i < *n; i++){
    scanf("%d",&a[i]);
  }
}

