#include <stdio.h>
#define N 100

int main(){

  int n,A[N],i,j,k,l,count=0,temp;

  int minj;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
 
    for(j=0;j<=n-1;j++){
      minj=j;

      for(l=j;l<=n-1;l++){
	if(A[l]<A[minj]){

	  minj=l;

      }

      }
      if(j != minj){
      temp=A[j];
	A[j]=A[minj];
	A[minj]=temp;
	count++;
      }
  }

  for(k=0;k<n;k++){
    if(k)printf(" ");
    printf("%d",A[k]);
    
  }

  printf("\n");

  printf("%d\n",count);

  return 0;
}

