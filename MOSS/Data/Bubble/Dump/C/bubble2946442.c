#include<stdio.h>
int main()
{   
    
  int A[100],N; 
  int i,j,temp,c=0;

  scanf("%d\n",&N);
 for(i = 0; i < N; i++){ 
  scanf("%d",&A[i]); 
 }

   for(i = 0; i < N-1; i++){ 
    for (j = N - 1; j > i; j--) {
      if (A[j-1] > A[j]) {
        temp = A[j-1];
       A[j-1] = A[j];
        A[j] = temp;
	c++;
      }
    }
  }

  for(i=0;i<N;i++) {
    if(N-1>i) printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n%d\n",c);
  return 0;
}

