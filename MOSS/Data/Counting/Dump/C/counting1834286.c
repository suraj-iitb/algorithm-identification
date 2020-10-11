#include<stdio.h>

#define N_MAX 2000005
#define k 10005


int A[N_MAX];
int B[N_MAX];
int C[k];
int n;

int main()
{
  int i, j;
  
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  for(i=0; i<k; i++){
    C[i] = 0;
  }
  
  for(j=0; j<=n; j++){
    C[A[j]]++;
  }
  
  for(i=0; i<k; i++){
    if(i==0)
      continue;
    C[i] =C[i] +  C[i-1];
    // printf("C[%d] = %d\n", i, C[i]);
  }
  
  for(j=n-1; j>=0; j--){
    B[C[A[j]]-1] = A[j];
    //    printf("B[%d] = %d\n",C[A[j]], B[C[A[j]]]);
    C[A[j]]--;
  }



  for(i=1; i<=n; i++){
    printf("%d", B[i]);
    
    if(i!=n)
      printf(" ");
    else
      printf("\n");
  }

  return 0;
}
