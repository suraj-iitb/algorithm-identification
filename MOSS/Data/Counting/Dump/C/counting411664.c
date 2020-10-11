#include<stdio.h>
#define N 2000001

int n;
int A[N],B[N],C[N];

void Countingsort(int k);

int main(){

  int i,max = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
    
    if(max <= A[i]){
      max = A[i];
    }

  }

  Countingsort(max);

  for(i = 0; i < n; i++){

    if(i == n-1){
      printf("%d\n",B[i]);
    } else {
      printf("%d ",B[i]);
    }
    
  }

  return 0;

}

void Countingsort(int k){
  
  int i,j;

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
  for(j = 0; j < n; j++){
    C[A[j]] = C[A[j]]+1;
    /* C[i]にはiの出現数が記録されている*/
  }
  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }
  /* C[i]にはi以下の数の出現数が記録されている*/
  for(j = n-1; j >= 0; j--){
    //    printf("%d: \n", j);
    //for(i=0;i<n;i++) printf("%d ", C[i]);
    //printf("\n");
    B[C[A[j]]-1] = A[j];
    C[A[j]] = C[A[j]]-1;
  }

}
