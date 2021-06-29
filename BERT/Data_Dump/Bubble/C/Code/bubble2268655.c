#include<stdio.h>
void swap(int *a,int *b); 
int count= 0;

int main()  {
  int i,j,flag,A[100],N,count=0;
  while(1) {
    scanf("%d",&N);
    if(1<=N && N<=100) break;
  }
  for(i=0;i<N;i++)  {
    scanf("%d",&A[i]);
  }

flag =1;
  i = 0;
  while(flag) {
    flag = 0;
    for (j = N-1; j>=i+1;j--) {
      if (A[j] < A[j-1]) {
	swap(&A[j],&A[j-1]);
	flag = 1;
       ++count;
      }
    }
    i++;
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
  *b =t;
}
