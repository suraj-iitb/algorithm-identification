#include <stdio.h>

void bubbleSort(int A[],int n){
  int i=0,j,temp=0;
  int flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	i++;
      }  
    }
   
  }   
  for(j=0;j<n;j++){
    
    printf("%d",A[j]);
    if(j!=n-1){      
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",i);
}



int main(){
  int n,A[100];
  int i;
  scanf("%d",&n);
  if(n>=1 && n<=100){
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
  
  bubbleSort(A,n);
  }
  return 0;
}

