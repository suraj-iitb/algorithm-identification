#include<stdio.h>

void swap(int *x,int *y){
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void bubbleSort(int a[], int n){
  int i,j,k;

  k=0;
  for(i=0; i<n-1; i++){
    for(j=n-1; j>=i; j--){
      if(a[j]<a[j-1]){
        swap(&a[j],&a[j-1]);
        k++;
      }
    }
  }
  for(i = 0; i<n-1; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",k);
}

int main(void){
  int i,n;

  scanf("%d",&n);

  int z[n];

  for(i = 0; i<n; i++){
    scanf("%d",&z[i]);
  }

  bubbleSort(z,n);

  return 0;
}

