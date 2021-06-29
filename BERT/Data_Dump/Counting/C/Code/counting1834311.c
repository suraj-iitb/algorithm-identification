#include <stdio.h>  
int A[2000000],B[2000000];
int main(){
int C[10001],i,j,n;
  scanf("%d",&n);

for(i=0;i<10001;i++)
     C[i]=0;

   for(i=1;i<n+1;i++){
     scanf("%d",&A[i]);
     C[A[i]]++;
    }
 /*CをC'にする*/

    for(i=1;i<10001;i++)
     C[i]=C[i]+C[i-1];

   for(j=1;j<=n;j++){
  B[C[A[j]]] = A[j];
    C[A[j]]--;
   }
    for(i=1;i<n;i++){
     printf("%d ",B[i]);
    }
  printf("%d\n",B[n]);
  return 0;
}
