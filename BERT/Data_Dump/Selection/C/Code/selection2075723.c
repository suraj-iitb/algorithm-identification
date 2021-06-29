#include<stdio.h>
void SelectionSort(int *,int);
#define N 100 
  
 main(){
   int i ,A[N] ,n;
   scanf("%d", &n);
   for(i = 0; i < n; i++) scanf("%d", &A[i]);
   SelectionSort(A, n);
 
  return 0;
}
 
 void SelectionSort(int *a, int b){
   int i,j,minj, koukan ,count=0;
   for(i=0; i < b; i++){
     minj = i;
     for(j=i; j < b ; j++) {
      if(a[j] < a[minj]){
     minj = j;
      }
    }
    
    if(i != minj) {
     count++;
    }
    koukan = a[i];
    a[i] = a[minj];
      a[minj] = koukan;
  }
   
  for(i=0; i < b - 1; i++){
  printf("%d ",a[i]);
  }
  printf("%d\n", a[b-1]);
  printf("%d\n", count);
}
