#include <stdio.h>
#define N 100

int main(){
  int n,k,j,i,v;
  int A[N];
  
  
    scanf("%d",&n);

    for(k=0;k<n;k++){
    scanf("%d",&A[k]);
    }

    for(i=1;i<=n;i++){
      for(j=0;j<n;j++){
	if(j)printf(" ");
	printf("%d",A[j]);
      }
      printf("\n"); 
      
      v=A[i];
      j=i-1;
      
      while(j>=0 && A[j]>v){
	
	A[j+1]=A[j];
	j--;
      }
      A[j+1]=v;
     
    }

    return 0;    
}

