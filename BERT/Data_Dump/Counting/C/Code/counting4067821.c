#include <stdio.h>
#define N  2000001

int B[N],C[N];

void CountingSort(int A[],int B[],int k,int n){
  int i,j;

for(i=0; i<=k; i++){
  C[i] = 0;
 }

     /* C[i] に i の出現数を記録する */
for(j=1; j<=n; j++){
  C[A[j]]++;
	   }

     /* C[i] に i 以下の数の出現数を記録する*/
for(i= 1; i<=k; i++){
  C[i] = C[i] + C[i-1];
 }

for(j=n; j>=1; j--){
  B[C[A[j]]] = A[j];
  C[A[j]]--;
 }

for(i=1; i<=n; i++){
  printf("%d",B[i]);
  if(i != n) printf(" ");
 }
printf("\n");

}

int main(){
 
  int A[N];
  int k=0,n, i, j;

  scanf("%d", &n);
for(i=1; i<=n; i++){
  scanf("%d",&A[i]);
  if(k<A[i]) k=A[i];
 }

 CountingSort(A,B,k,n);


  return 0;
}



