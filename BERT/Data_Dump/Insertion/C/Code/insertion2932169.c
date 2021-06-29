#include<stdio.h>

main(){
  int i,n,v,j,k;
    
    scanf("%d",&n);
    
    int A[n];
    
    for(i=0;i<n;i++)
      {
	scanf("%d",&A[i]);
      }
    
    
    for(i=1;i<n;i++)
      {
	for(k=0;k<n;k++)
	  {
	    printf("%d",A[k]);
	    if(k+1!=n){
	        printf(" ");
	    }
	  }
	printf("\n");
	
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v)
        {
	  A[j+1]=A[j];
	  j--;
	}
	A[j+1]=v;
      }
    
    for(i=0;i<n;i++)
      {
        printf("%d",A[i]);
        if(i+1!=n){
            printf(" ");
        }
        
	}
   printf("\n");
}


