#include <stdio.h>

#define M 100

void insertion_Sort(int [], int);
void Print(int [], int);

int main(){
    int A[M],N;
    int i,j;
    
    scanf("%d",&N);
    for(i=0;i<N;i++)
      scanf("%d",&A[i]);
    
    for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j!=N-1) printf(" ");
    }
    printf("\n");
    
    insertion_Sort(A,N);
    
    return 0;
}

//順番を入れ替える、入れ替えたら、print関数で出力
void insertion_Sort(int A[],int N)
{
  int v;
  int i,j;

    
  for(i=1;i<N;i++)
    {
      v=A[i];
      //insert A[i] into the sorted sequence A[0,...,j-1]
      j=i-1;
      while(j >= 0 && A[j] >v)
        {
	  A[j+1]=A[j];
	  j--;
        }
      A[j+1]=v;
      Print(A,N);
    }
}

//出力
void Print(int A[],int N){
  int i;

  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1) printf(" ");
    }
  printf("\n");
}

