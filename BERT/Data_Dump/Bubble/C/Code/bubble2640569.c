#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j, temp;
  int A[N+1];
  int count=0;
  scanf("%d", &n);

  for (i=0;i<n;i++) scanf("%d", &A[i]);

  for (i=0;i<n;i++)
  {
    for (j=n-1;j>i;j--)
    {
      if (A[j-1]>A[j])
      {
        temp=A[j];
        A[j]=A[j-1];
        A[j-1]=temp;
        count++;
      }
    }
  }

  trace(A, n);

  printf("%d\n",count);
  
  
  return 0;
}
