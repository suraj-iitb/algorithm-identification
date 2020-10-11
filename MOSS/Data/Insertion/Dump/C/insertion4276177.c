#include <stdio.h>
 
void insertionSort(int A[],int N);
 
 int main(void)
 {
    int i,N;
    scanf("%d",&N);
    int A[N];
    for (i = 0;i < N;i++) {
        scanf("%d",&A[i]);
    }
    insertionSort(A,N);
    return 0;
 }

 void insertionSort(int A[],int N)
 {
  int i,v,j,e;
   for (i = 1;i < N + 1;i++) {
     for (e = 0;e < N;e++) {
	if (e == N - 1)
		printf("%d\n",A[e]);
        else printf("%d ",A[e]);
     }
     if (i == N)
	return;
     v = A[i];
     j = i - 1;
     while (j >= 0  && A[j] > v) {
       A[j + 1] = A[j];
       j--;
     A[j + 1] = v;
     }
   }
 }
