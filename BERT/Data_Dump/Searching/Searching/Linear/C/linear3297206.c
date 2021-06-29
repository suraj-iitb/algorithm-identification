#include <stdio.h>

int main()
{
  int i,n,q,A[10000+1],key,count=0,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);

    j=0;
    A[n] = key;
    while(A[j] != key && j<n){
      j++;
    }
    if(j == n);
    else count++;
  }

    printf("%d\n",count);

    return 0;
  }

    
  
  

