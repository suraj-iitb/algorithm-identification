#include<stdio.h>
#include<stdlib.h>
int main(){
  
  int n,i,j,flag=1,hozon,z=0;

  scanf("%d",&n);
  int *A;
  A=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if (A[j]<A[j-1]) {
	
	hozon = A[j];
	A[j]=A[j-1];
	A[j-1]=hozon;
	flag=1;
	z++;
      }
      
    }
  }

    for(i=0;i<n;i++){
      printf("%d",A[i]);
      if(i!=n-1) printf(" ");
      else printf("\n%d\n",z);
    }

    return 0;
  }

