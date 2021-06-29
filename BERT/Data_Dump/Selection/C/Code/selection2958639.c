#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,w,minj,tmp
    ;
  int *A;
  int n,count=0;


  scanf("%d",&n);

  A=(int *)malloc(n*sizeof(int));

for(i=0; i<n ; i++){
    scanf("%d",&A[i]);
      }

  
  for(i=0; i<n; i++){
    minj = i;
    for(j=i+1; j<n; j++){
      if(A[j] < A[minj]){
	minj =j;
      }
    }

    if(A[i]>A[minj]){
	tmp=A[i];
	A[i]=A[minj];
	A[minj]=tmp;
	count++;
    }
      }
  
   for(w=0; w<n ; w++){

    if(w==n-1){
      printf("%d\n",A[w]);
      break;
    }
    
      printf("%d ",A[w]);
  
}


  printf("%d\n",count);
  
  return 0;
}

