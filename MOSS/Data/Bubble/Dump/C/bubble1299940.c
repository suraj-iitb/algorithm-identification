#include<stdio.h>
#define N 100

main(){
  int n,i,j,t,A[N],flag,x,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  } 
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	x = A[j];
        A[j]= A[j-1];
	A[j-1]= x;
        flag=1; 
	count++;     
      }   
    }
    i++;  
  }  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i==n-1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
