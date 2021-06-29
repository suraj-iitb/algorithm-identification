#include <stdio.h>

int main(){
  int n,i,j,min,x,count=0,befor;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  for(i=0;i<n;i++){
    
    befor=A[i];
    min=i;

      for(j=i;j<n;j++){
	if(A[j]<A[min]){
	  min=j;
	}
      }

    x=A[i];
    
    A[i]=A[min];
    
    A[min]=x;

    if(befor!=A[i])count++;

  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");

  }

  printf("\n%d\n",count);

  return 0;

}
  

