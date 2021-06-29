#include <stdio.h>

void Sort(void);
int k = 0,n,A[2000001],B[2000001];

main(){

  int i;

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++){
    scanf("%d",&A[i]);
    if(A[i] > k) k = A[i];
  }

  Sort();

  return 0;
}
void Sort(void){

   int C[k + 1];
   int i;
   k = k + 1;

   for(i = 0 ; i < k ; i++){
     C[i] = 0;
   }

   for(i = 1 ; i <= n ; i++ ){
     C[A[i]]++;
   }

   for(i = 1 ; i < k ;i++ ){
     C[i] = C[i] + C[i - 1];
   }

   for(i = n ; i >= 1 ;i-- ){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
   }

   for(i = 1 ; i <= n; i++){
     printf("%d",B[i]);
     if(i < n)printf(" ");
   }

   printf("\n");


}
