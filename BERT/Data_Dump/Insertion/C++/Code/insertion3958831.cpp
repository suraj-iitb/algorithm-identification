#include<stdio.h>

int main(){
  int n,k,i,j;
  int v;
  int A[100];
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&A[i]);

  for(j=1;j<=n;j++)
    {   
	      v = A[j];		
	      i = j-1;
	      while(i>0 && A[i]>v)
		{
		  A[i+1]=A[i];  
		  i = i-1;
		}
	      A[i+1] = v;
	      for(k=1;k<=n;k++){
		if(k == n)printf("%d\n",A[k]);
		else printf("%d ",A[k]);
	      }
    }
  
  return 0;
}

