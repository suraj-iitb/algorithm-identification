#include <stdio.h>

int main(){

  int tmp,i,j,A[100],n,k,count=0;

  scanf("%d",&n);
    for(k=0;k<n;k++){
      scanf("%d",&A[k]);
    }
  for(i=1;i<=n;i++){
    for(j=n-1;j>=1;j--){

      if(A[j]<A[j-1]){
	tmp=A[j];
      A[j]=A[j-1];
      A[j-1]=tmp;
          count++;
      }
  
    }
  }
  
      for(i=0;i<n-1;i++){
	printf("%d ",A[i]);
	  }
      printf("%d\n",A[n-1]);
      printf("%d\n",count);
      return 0;
      
	}

