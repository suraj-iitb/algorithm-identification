#include <stdio.h>
#include <string.h>
void X(int *A,int N)
{
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}


void Sort(int *A,int N)
{
  
  int i,j,k;

  for(i=1;i<N;i++){
    k=A[i];
    j=i-1;
    
    while(j>=0&&A[j]>k){
      A[j+1]=A[j];
    j--;
    }
    A[j+1]=k;
    X(A,N);
  }
}



int main()
{
  
  int i,n,A[1000];

  scanf("%d",&n);
    
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  X(A,n);
 Sort(A,n);
    
  return 0;
}



