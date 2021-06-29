#include<stdio.h>
#define N 100
  

int main()
{
  int i,j,minj,key,n,count=0;
  int A[N];
  scanf("%d",&n);
  
  for(i=0;i<=n-1;i++) scanf("%d",&A[i]);
  

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]) minj=j;
    }
 

   key=A[i];
   if(minj!=i){
  
    A[i]=A[minj];
    A[minj]=key;
    count++;
    }
  }
 
  for ( i = 0; i < n-1; i++ ){
  
  printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);
  
  printf("%d\n",count);
  return 0;
}
