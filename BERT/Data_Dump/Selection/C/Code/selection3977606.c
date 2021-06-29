#include<stdio.h>

void swap(int *x,int *y){
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void selectionSort(int a[], int n){

  int i,j,k,minj;

  k=0;
  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
    if(a[i]!=a[minj]){
      swap(&a[i],&a[minj]);
      //printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
      k++;
    }
  }
  for(i=0; i<n-1; i++){
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

  selectionSort(z,n);

  return 0;
}

