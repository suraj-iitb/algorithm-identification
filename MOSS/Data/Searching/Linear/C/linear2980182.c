#include<stdio.h>
#include<stdlib.h>
int main(){
  int n1,n2;
  int *A,*B;
  int i,j,count=0;
  
  scanf("%d",&n1);


   A  = (int *)malloc(n1 * sizeof(int));
   
  for(i=0;i<n1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&n2);

  B  = (int *)malloc(n2 * sizeof(int));
   
    
    for(i=0; i<n2; i++){
      scanf("%d",&B[i]);
    }

  for(j=0; j<n2; j++){
    for(i=0; i<n1; i++){
      if(A[i]==B[j]){
	count++;
	break;
      }
    }
  }
    printf("%d\n",count);
    return 0;
  }
 

