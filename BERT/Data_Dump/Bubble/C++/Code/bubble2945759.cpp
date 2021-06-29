#include <stdio.h>

int main(){
  int n,A[100],i,j,temp,c=0;

  scanf("%d",&n);

  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }

  for(i=0 ; i<n ; i++){
    for(j=n-1; j>i ;j--){
      if(A[j] < A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	c++;
      }
    }
  }

  for(i=0 ; i<n ; i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n");
  printf("%d\n",c);
  
  return 0;
}

