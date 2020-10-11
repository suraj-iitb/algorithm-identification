#include <stdio.h>
#define N 100

int main(){
  int i = 0, j = 0, k = 0, n = 0;
  int A[N];
  int miji = 0, key = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < n; i++){
    miji = i;
    for(j = i; j < n; j++){
      if(A[j] < A[miji]){
	miji = j;
      }
    }
    if(A[i] != A[miji]){
      key = A[i];
      A[i] = A[miji];
      A[miji] = key;
      k++;
    }
  }

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",k);
  return 0;
}

