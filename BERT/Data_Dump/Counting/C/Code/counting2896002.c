#include<stdio.h>
 #define MAX 2000000
 #define K 10010
 int A[MAX], B[MAX];
 void CountingSort(int A[], int N, int B[])
 {
 int C[K] ={0};
 for (int i = 0;
 i < N;
 i++)
 {
 C[A[i]]++;
 }
 for (int i = 1;
 i < K;
 i++)
 {
 C[i] += C[i - 1];
 }
 for (int i = N - 1;
 i >= 0;
 i--) { C[A[i]]--;
 B[C[A[i]]] = A[i];
 }
 }
 int main()
 {
 int N;
 scanf("%d", &N);
 for (int i = 0; i < N; i++)
 {
 scanf("%d", &A[i]);
 }
 CountingSort(A, N, B);
 for (int i = 0; i < N;
 i++)
 {
 if (i)printf(" ");
 printf("%d",B[i]);
 }
 printf("\n");
 return 0;
 }
