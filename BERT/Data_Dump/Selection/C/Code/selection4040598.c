#include <stdio.h>
#define N 100
int main(){
  int i,j,n,A[N],temp,minj,cunt = 0;
  scanf("%d",&n);
  for(i = 0; i < n;i++){
    scanf("%d",&A[i]);
  }
  for(i =  0;i <= n-1;i++){
    minj = i;
    for(j =  i;j <= n-1;j++){
      if (A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] > A[minj])cunt++;
    temp = A[minj];
    A[minj] = A[i];
    A[i] = temp;
    
  }
  for(i = 0;i < n;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d",cunt);
  printf("\n");
  return 0;
}

