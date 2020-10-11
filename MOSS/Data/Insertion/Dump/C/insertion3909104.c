#include<stdio.h>

int insertionsort(int,int);

int main(void){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(int k=0; k<n-1; k++){
    printf("%d ",a[k]);
  }
  printf("%d",a[n-1]);
  printf("\n");

  insertionSort(a,n);

  return 0;
}

int insertionSort(int a[],int n){
  int j,v;

  for(int i=1; i<=n-1; i++){

    v = a[i];
    j = i-1;
    while((j>=0)&&(a[j]>v)){
      a[j+1]=a[j];
      j--;


    }
    a[j+1] = v;

    for(int k=0; k<n-1; k++){
      printf("%d ",a[k]);
    }
    printf("%d",a[n-1]);
    printf("\n");

  }



  return 0;


}

