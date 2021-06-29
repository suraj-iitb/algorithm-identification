#include<stdio.h>
int main(){



  int N=0,i,j,v,s;
  
  scanf("%d",&N);

  
  int A[N];

 
  for(s=0;s<N;s++) scanf("%d",&A[s]);

  for(s=0;s<N;s++){ if(s==0)printf("%d",A[s]); 
     else printf(" %d",A[s]);} 
  printf("\n");

  for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
    
      while(j>=0 && A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	  A[j+1]=v;



	}
     for(s=0;s<N;s++){ if(s==0)printf("%d",A[s]); 
     else printf(" %d",A[s]);} 
     printf("\n");
    }




  
    return 0;
}

