#include<stdio.h>
#define M 100

void trace(int *,int);
void insert(int *,int);

int main() {

  int i;
  int number;
  int num[M];

  scanf("%d",&number);
  for(i=0;i<number;i++) scanf("%d",&num[i]);

  trace(num,number);

  insert(num,number);
  
  return 0;
  
}

void trace(int *A,int N) {
  int i;

  for(i=0;i<N;i++) {
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void insert(int *A,int N) {
  int j,i,v;

  for(i=1;i<N;i++) {
    v = A[i];
    j=i-1;
    while(j>=0 && A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A,N);
  }
}
