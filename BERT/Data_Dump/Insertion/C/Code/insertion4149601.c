#include<stdio.h>
#define N 1000

void insertionSort(int *, int);
  
int main(){
  int n,a[N];
  int i,j,k;
  int key;
  
 scanf("%d",&n);
  if(n <= 0 && n >= 100) return 0;

  for(i = 0 ; i <= n-1 ; i++) scanf("%d",&a[i]);
  insertionSort(a,n);
   for(k =0; k <= n-2; k++){
      printf("%d ",a[k]);
 }
   printf("%d",a[k]);
   printf("\n");
  return 0;
}
void insertionSort(int *a, int n){
  int i,j,k,key;
  
 for(i = 1 ; i <= n-1; i++){
    key = a[i];
    j = i - 1;
    for(k =0; k <= n-2; k++){
      printf("%d ",a[k]);
    }
    printf("%d",a[k]);
    printf("\n");
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    a[j+1] = key;
    }
  }
}

