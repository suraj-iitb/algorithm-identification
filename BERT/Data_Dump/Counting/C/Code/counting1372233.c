#include <stdio.h>

#define N 2000001
#define K 10000

int A[2000001];
int B[2000001];
int C[10000];

void CountingSort(int,int);

int main(){
  int n,i,j;

  scanf("%d",&n);
  for(i=1;i<n+1;i++) scanf("%d",&A[i]);
    CountingSort(K,n);
   
     for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);
    
  return 0;
}

void CountingSort(int k,int n){
  int i;

  for(i=0;i<k;i++) C[i]=0;

   for(i=1;i<n+1;i++) C[A[i]]++;

    for(i=1;i<k;i++)  C[i]+=C[i-1];


     for(i=n;i>0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
    }

}
