#include <stdio.h>
int main()
 {
   int i,j,N,key,k;
   int A[1000];

   scanf("%d",&N );
   for ( i = 0; i <= N-1; i++) {
   scanf("%d",&A[i]);
 }
 for(i=1;i<=N-1;i++){
 for(k=0;k<=N-1;k++){
 if(k != N-1) printf("%d ",A[k]);
 else printf("%d\n",A[k]);
}
 key = A[i];
  j= i-1;

 while (j>=0 && A[j] > key) {
   A[j+1] = A[j];
   j--;
 }
   A[j+1] = key;
 }
  for(i=0; i <= N-1;i++){
  if(i != N-1) printf("%d ",A[i]);
  else printf("%d\n",A[i]);
}


  return 0;
}

