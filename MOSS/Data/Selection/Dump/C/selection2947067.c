#include <stdio.h>

#define Max 100
#define Min 1
#define AMAX 100

int main(){
  int i,j,n,A[AMAX],minj,tmp,cnt=0;

  scanf("%d",&n);

  if(n >= Min && n <= Max)
    for(i=0; i<n; i++)
      scanf("%d",&A[i]);

  for(i=0; i<n; i++){
    minj = i;
    for(j=i+1; j<n; j++)
      if(A[j] < A[minj]) 
	minj = j;
    if(minj != i){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      cnt++;
    }
  }

  for(i=0; i<n; i++)
    i == n-1 ? printf("%d\n",A[i]) : printf("%d ",A[i]);

  printf("%d\n",cnt);

  return 0;
}
    
  
    

