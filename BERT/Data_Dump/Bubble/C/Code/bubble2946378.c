#include <stdio.h>
int main(){

  int n,i,j,flag,v,k,count = 0;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;

  i = 0;


  while(flag){

    flag = 0;
   
    for(j=n-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	v = A[j];
	A[j] = A[j-1];
	A[j-1] = v;
	flag = 1;
	count++;
      }
    
    }
    i++; 
   
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);

    if(i<n-1){
      printf(" ");
    }

    else{
      printf("\n");
    }
  }

 
  printf("%d\n",count);
  return 0;
}

