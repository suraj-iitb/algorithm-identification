#include<stdio.h>

int main(){
  int N,k,p,j;
  int key;
  int A[110];
  scanf("%d",&N);
  
  for(p=1;p<=N;p++)scanf("%d",&A[p]);

  for(j=1;j<=N;j++)
    {   
	      key=A[j];		
	      p=j-1;
	      while(p>0 && A[p]>key)
		{
		  A[p+1]=A[p];  
		  p=p-1;
		}
	      A[p+1]=key;
	      for(k=1;k<=N;k++){
		if(k == N)printf("%d\n",A[k]);
		else printf("%d ",A[k]);
	      }
    }
  
  return 0;
}

