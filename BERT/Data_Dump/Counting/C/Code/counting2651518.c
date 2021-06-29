#include<stdio.h>
 
void counting_sort(int);
int C[2000001], A[2000001],B[2000001];
int n;
 
main(){
  
  int max=0;
  int i,j;
   
  scanf("%d",&n);
  for(i=1; i <= n; i++){
    scanf("%d",&A[i]);
    if(max < A[i])
      max = A[i];
  }
   
  counting_sort(max);
   
  for(i=1; i<=n; i++){
    printf("%d",B[i]);
    if((i>0) && (i<n))
      printf(" ");
  }
  printf("\n");
   
  return 0;
}
 
 
void counting_sort(int k){
  int i,j;
   
  for(i=0; i <= k; i++){
    C[i] = 0;
  }
  for(j=1; j <= n; j++){
    C[A[j]] = C[A[j]] + 1;
  }
  for(i=1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
}
