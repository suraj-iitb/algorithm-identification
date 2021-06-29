#include <stdio.h>

int main() {

  int flag,i,j,A[100],k,N,count=0;



  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }


  flag=1;
  
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	count++;
	flag=1;
      }
      
      //flag=1;
     
    }
    
  }

    for(i=0;i<N;i++){
      if(i!=0){
	printf(" ");
      }
      printf("%d",A[i]);
    }

    printf("\n%d\n",count);
    
    return 0;
  }

