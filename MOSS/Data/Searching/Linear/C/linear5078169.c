#include<stdio.h>


int search(int A[], int n, int door){
  
  
  int i;
  
  for (i = 0;i < n;i++){
    if (A[i]==door) return 1;
  }
  return 0;
}

main(){
  
  
  int i, n, A[10000], p, door, sim = 0;
  
  scanf("%d",&n);
  for (i = 0; i <n;i++) scanf("%d", &A[i]);
  scanf("%d", &p);
  for ( i = 0; i < p; i++ ){
    scanf("%d", &door);
    
    if ( search(A, n, door) ) sim++;
  }
  printf("%d\n", sim);


    return 0;
}
