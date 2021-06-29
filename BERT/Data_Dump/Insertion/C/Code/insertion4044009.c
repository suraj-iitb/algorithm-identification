#include<stdio.h>

int main(){
  int o,n,k,i,j;
  int kkk;
  int A[110];
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&A[i]);
  for(j=1;j<=n;j++)
    {   
      kkk = A[j];		
      i = j-1;
      while(i>0 && A[i]>kkk)
	{
	  A[i+1]=A[i];  
	  i = i-1;
	}
      A[i+1] = kkk;
      for(k=1;k<=n;k++){
	if(k == n)printf("%d\n",A[k]);
	else printf("%d ",A[k]);
      }
    }
  
  return 0;
}

