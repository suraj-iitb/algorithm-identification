#include <stdio.h>

void selectionSort(int A[],int n){
  int i,temp,count=0,j;
  int minj;
  
  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj)count++;
  }
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}

 
int main(){

  int n,i=0;
  int A[100];

  scanf("%d",&n);
  if(n>=1 && n<=100){
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
    //printf("a\n");
    selectionSort(A,n);
    
  }	  
  return 0;
}

