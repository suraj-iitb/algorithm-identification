#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int C[VMAX+1],n;

void CountingSort(short *,short *,int);

int main(){
unsigned short *A, *B;
int i,j,k=0;
	
  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  /* your code */

for( j = 1; j <= n; j++){
 scanf("%d",&A[j]);
if(A[j]>k)k=A[j];
}
 CountingSort(A,B,k);

for(i=1;i<=n;i++){
  printf("%d",B[i]);
 if (i != n) printf(" ");
 }

printf("\n");
free(A);
free(B);

return 0;
}

void CountingSort(short A[],short B[],int k){
int i,j;

for( i = 0; i<=k; i++){
  C[i] = 0;
 }

/* C[i] �� i �̏o�������L�^���� */
for(j=1;j<=n;j++){
  C[A[j]]++;
 }

/* C[i] �� i �ȉ��̐��̏o�������L�^����*/
for( i = 1; i<=k; i++){
  C[i] += C[i-1];
 }

for (j = n; j > 0; j--){
  B[C[A[j]]] = A[j];
  C[A[j]]--;
 }
}


