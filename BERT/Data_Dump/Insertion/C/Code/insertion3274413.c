#include <stdio.h>
#define Aa 1000
int main(){
  int A[Aa];
  int n=0,i=0,j=0,v=0,k=0;
  scanf("%d",&n);
  for(i = 0;i < n; i++){
    scanf("%d",&A[i]);
  }
  for(k = 0;k < (n-1); k++){
    printf("%d ",A[k]);
  }
  printf("%d\n",A[k]);
for(i = 1; i < n; i++){
  v = A[i];
  j = i - 1;
  while(j >= 0 && A[j] > v){
    A[j + 1] = A[j];
    j--;
    A[j + 1] = v;
  }
  for(k = 0;k < (n-1); k++){
    printf("%d ",A[k]);
  }
  printf("%d\n",A[k]);
 }
return 0;
}

