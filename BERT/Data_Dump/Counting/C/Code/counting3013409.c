#include<stdio.h>
#define k 10000
  int A[2000000];
  int B[2000000];
int main(){
  int i,n,j;
  int C[k+1];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  

  for(i=0;i<k;i++){
    C[i]=0;
  }
  /* for(i=0;i<n-1;i++){
    printf("%d ",B[i]);
    }
    printf("%d\n",B[n-1]);
  */
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<k;i++){
    C[i]= C[i] + C[i-1];
  }
  for(j=n;j>=0;j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",B[i]);
      }
  printf("%d\n",B[n-1]);
  return 0;
}

