#include<stdio.h>
void insertionSort(int a[],int n);
int main(void){
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  return 0;
}
void insertionSort(int a[],int n){
  int i,j,k,v;
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(k=0;k<n-1;k++){
      printf("%d ",a[k]);
    }
    printf("%d\n",a[n-1]);
  }
}
