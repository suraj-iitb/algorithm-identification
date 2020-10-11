#include<stdio.h>
#define N 100 

int main(void) {

  int i,tmp,j,A[N],n,cnt=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  
  for(i=0;i<=n-1;i++) {
    for(j=n-1;j>=i+1;j--) {
      if(A[j] < A[j - 1]) {
	tmp = A[j];	
	A[j] = A[j-1];
	A[j-1] = tmp;
	cnt++;
      } 
    }
  }
  for(i=0;i<n;i++) {

    printf("%d",A[i]);
    if(i < n-1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;

}
