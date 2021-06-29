#include<stdio.h>
#define MAX 1000

void insertionSort(int *,int);

main(){
  int i,n,a[100];
  
  scanf("%d",&n);
  
  for(i=0;i < n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i < n-1;i++){
    printf("%d ",a[i]);
  }   
  printf("%d\n",a[n-1]);
  
  
  insertionSort(a,n);
  
  return 0;
}
void insertionSort(int *a,int n){
  int i,j,q,v;
  
  for(i = 1;i < n;i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 &&a[j] > v){
      a[j + 1] = a[j];
      j--;
      a[j+1] = v;
    }
    for(q=0;q < n-1;q++){
      printf("%d ",a[q]);
    }   
    printf("%d\n",a[q]);
  }
}
