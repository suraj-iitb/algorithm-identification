#include<stdio.h>
void swap(int *a,int *b); 

int main()  {
  int i,j,A[100],N,count=0,minj;
  while(1) {
    scanf("%d",&N);
    if(1<=N && N<=100) break;
  }

  for(i=0;i<N;i++)  {
    scanf("%d",&A[i]);
  }

  for(i = 0;i <=N-1;i++) {
    minj = i;
    for (j = i; j <= N-1; j++) {
      if (A[j] < A[minj]) {
	minj = j; 
      }
    }
	swap(&A[i],&A[minj]);
	if(minj != i) count++;
  }


  for(i=0;i<N-1;i++) 
    printf("%d ",A[i]);
  
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}

void swap(int *a,int *b)
{ 
  int t; 
  t =*a; 
  *a = *b;
  *b=t;
}
