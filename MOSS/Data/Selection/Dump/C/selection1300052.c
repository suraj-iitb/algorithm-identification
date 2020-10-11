#include<stdio.h>
#define N 100
main()
{
  int A[N],i,j,x,n,flag,minj,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    minj=i;
    flag=0;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
      x=A[i];
      A[i]=A[minj];
      A[minj]=x; 
      count++;
    }
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
