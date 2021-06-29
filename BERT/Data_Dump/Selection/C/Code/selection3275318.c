#include <stdio.h>
#define N 100

int main(){
  int n,i,j,A[N],minj,temp,count=0,m;

  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  for(i=0;i<n-1;i++){
    minj = i;
    m = A[i];
    
    for(j=i;j<n;j++){
      if(A[j] < m){
	m = A[j];
	minj = j;
      }
    }
    if(m != A[i]){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    count++;
  }
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

