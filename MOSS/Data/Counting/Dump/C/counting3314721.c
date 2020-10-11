#include  <stdio.h>


int main()
{

  int i, j, n;
  int C[100000];
  
  scanf("%d",&n);
  int A[n+1], B[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }

  for(i=0;i<=10000;i++){
    C[i] = 0;
  }
	    
  for(i=0;i<n;i++){
    C[A[i+1]]++;
  }

  for(i=1;i<=10000;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=1;j<=n;j++){ 
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;

}

