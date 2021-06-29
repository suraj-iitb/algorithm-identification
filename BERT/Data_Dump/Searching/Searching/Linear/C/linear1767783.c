#include <stdio.h>

int linearSearch(int A[],int n,int key)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(A[i]==key)
	{
	  return 1;
	}
    }
return 0;
}

int main ()
{
  int i,n,n2,A[10000],key,judge=0;

  scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
  
    scanf("%d",&n2);
      for(i=0;i<n2;i++){
	scanf("%d",&key);
      
     
    if(linearSearch(A,n,key))
      {
	judge++;
      }
      }
    printf("%d\n",judge);
    return 0;
}
