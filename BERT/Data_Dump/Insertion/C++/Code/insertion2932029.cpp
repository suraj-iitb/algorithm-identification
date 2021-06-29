#include<stdio.h>
#define N 100



void output(int A[], int n){

  int i;

  printf("%d",A[0]);

  for(i=1;i<n;i++)
    printf(" %d",A[i]);
  putchar('\n');
  
}

void insertionsort(int A[], int n){
  int v=0;
  int i,j;

  for(i=1; i<=n-1; i++){

    v=A[i];
    j=i-1;

    while(j >=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    output(A, n);
  }
}

int main(void){
  int A[N],n,i,j;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);

  output(A,n);

  insertionsort(A,n);
  
 
  return 0;

}

