#include <stdio.h>

void Print(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

void insertionSort(int a[],int n){
  int i,j,v;
  Print(a,n);
  for(i=1;i<n;i++){

    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]= v;
      }
      Print(a,n);
  }
}

int main(void){
  int n,i;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  insertionSort(a,n);

  return 0;
}

