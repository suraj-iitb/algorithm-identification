#include<stdio.h>
 
#define MAX 100
 
int main(void){
 
  int x, n, A[MAX], i, j, c=0;
  int cnt=0;
 
  scanf("%d",&n);
 
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
 
  while(1){
 
    for(j = n-1; j > 0; j--){
      if(A[j] < A[j-1]){
	x = A[j];
	A[j] = A[j-1];
	A[j-1] = x;
	c++;
      }
      else cnt++;
    }
    if(cnt != n-1) cnt=0;
    if(cnt == n-1) break;
  }
 
  for(i = 0;i < n; i++){
    printf("%d",A[i]);
    if(i != n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",c);
 
  return 0;
}

