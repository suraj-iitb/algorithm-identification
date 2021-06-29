#include <stdio.h>
int main()
{
  int i, j, k, tmp, n, A[1000];
   
 
  scanf("%d", &n);
   
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
  }
   
   
  for(i=1;i<=n;i++){
 
    for(k=0; k<n; k++){
      printf("%d",A[k]); 
      if(k<n-1)printf(" ");
    }
 
    printf("\n");
    tmp=A[i];  
    j=i-1;
    while(j>=0 && A[j]>tmp){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=tmp;
  }
  return 0;
}
 
  
