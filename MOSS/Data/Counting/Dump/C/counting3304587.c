#include<stdio.h>

#define I 2000001
#define N 10000

void countingSort(int);

int A[I];
int B[I];
int C[N];

int main() {
  int i,x;

  scanf("%d",&x);
  for(i = 1; i < x + 1; i++) {
    scanf("%d",&A[i]);
  }

  countingSort(x);

   for(i = 1; i < x; i++) {
     printf("%d ",B[i]);
   }
     printf("%d\n",B[i]);

   return 0;
}

void countingSort(int a) {
  int i;

  for(i = 0; i <= N; i++) {
    C[i] = 0;
  }

  for(i = 1; i <= a; i++) {
    C[A[i]]++;
  }

  for(i = 1; i <= N; i++) {
    C[i] = C[i] + C[i - 1];
  }
  
  for(i = a; i > 0; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}
  
   
  

