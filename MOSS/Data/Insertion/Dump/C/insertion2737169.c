#include<stdio.h>

void insert(int A[],int N);
void show(int A[],int N);

  void insert(int A[], int N) {
  int j;
  int i;
  int tr;
  int f;
    for (int  i = 1; i < N; i++) {
      j=i-1;
      f=A[i];
      while(0<=j && A[j]>f){
          j--; //where to put f
        }
      for(int a=i-1;a>=j;a--){
          A[a+1]=A[a];
      }

        A[j+1]=f;
        show(A,N);
      }
    }

  void show(int A[],int N){
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if(i!=N-1)printf(" ");
    }
    printf("\n");
  }
  int main(){
  int A[100];
  int N;
  scanf("%d",&N);
  for (int  i = 0; i < N; i++) scanf("%d",&A[i] );
  show(A,N);
  insert(A,N);

}
