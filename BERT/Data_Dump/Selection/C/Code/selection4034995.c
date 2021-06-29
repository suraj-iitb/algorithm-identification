#include <stdio.h>
#define M 100

int Selectsort(int,int *);

int main()
{
  int A[M], i = 0,v,limit,count=0;
  scanf("%d", &limit);
  for(i=0;i<limit;i++){
    scanf("%d", &A[i]);
    if (i == M-1)break;
  }
  //for(i=0;i<limit;i++)printf("%d",A[i]);
  v = Selectsort(limit,A);
  for (i = 0; i < limit - 1; i++) printf("%d ", A[i]);
  printf("%d\n%d\n", A[limit - 1],v);
	
  return 0;
}

int Selectsort(int N,int *A)
{
  int minj, i,j,kari,v=0;
  for (i = 0; i < N; i++) {
    minj = i;
    //printf("%d",minj);
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) {
	minj = j;
	
	//printf("a");
      }
    }
    if(A[i]!=A[minj])v++;
    kari = A[i];
    A[i] = A[minj];
    A[minj] = kari;
  }
  return  v;

}

