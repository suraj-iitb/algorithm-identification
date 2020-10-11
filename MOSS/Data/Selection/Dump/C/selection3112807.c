#include <stdio.h>
 
int main(){
  int i,j,n;
  int cnt=0;
  int mini;
  scanf("%d",&n);
  int A[n];
 
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
   
  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++)
      if(A[j] < A[mini])
    mini = j;
    if(mini != i){    
      int tmp = A[i];
      A[i] = A[mini];
      A[mini] = tmp;
      cnt++;
    }
  }
   
  for(i=0; i<n-1; i++)
    printf("%d ",A[i]);
   
  printf("%d\n%d\n",A[n-1],cnt);
  return 0;
}
