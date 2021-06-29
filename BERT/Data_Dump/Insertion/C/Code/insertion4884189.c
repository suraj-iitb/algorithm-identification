#include<stdio.h>

#define K 100

void print(int N, int A[]);
void insertionSort(int N,int A[]);

int main(void)
{
    int i;
    int N,A[K];

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        }

    print(N,A);
    insertionSort(N,A);

    return 0;
}

void print(int N, int A[])
{
  int i;
  for(i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
   }
   printf("\n");
}

void insertionSort(int N,int A[])
{
    int i,j,v;
    for(i=1;i<N;i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(N, A);
    }
}
