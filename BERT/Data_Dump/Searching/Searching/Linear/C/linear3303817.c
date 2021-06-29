#include<stdio.h>
#define N 10000

int main()
{
  int i,j,n,q;
  int A[N],count=0,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
    

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      A[n]=key;
      for(j=0;A[j]!=key;j++){
      }
      if(j==n) continue;
      count++;
    }
  

  printf("%d\n",count);

  return 0;
}
	






  

  


