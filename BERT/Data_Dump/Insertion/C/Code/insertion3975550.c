#include<stdio.h>

void insertionSort(int a[], int n){
  int i,j,k,x;

  /*for(i=0; i<n-1; i++){
      printf("&d ",a[i]);
  }
  printf("%d\n",a[i]);*/

  for(i=0; i<n; i++){
    x = a[i];
    j = i - 1;
    while((j>=0) && (a[j]>x)){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = x;

    for(k=0; k<n-1; k++){
      printf("%d ",a[k]);
    }
    printf("%d\n",a[k]);
  }
}

int main(void){

  int n;
  scanf("%d",&n);

  int a[n];

  for(int i=0; i<n; i++){
    scanf("%d ",&a[i]);
  }

  insertionSort(a,n);

  return 0;
}
