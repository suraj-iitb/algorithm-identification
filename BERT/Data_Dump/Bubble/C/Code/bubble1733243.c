#include<stdio.h>
#define N 100

int main()
{
  int i,j,n,k=0,flag=1,temp;
  int A[N];
  int count=0;
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  while(flag == 1){
    flag = 0;

    for(j = n-1 ; j >= k+1 ; j--){

      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag =1;
	count+=1;
      }
 }  
    if(flag == 1) k=+1;
  }
    for(i = 0 ; i < n-1 ; i++){
    printf("%d ",A[i]);
    }

    printf("%d\n%d\n",A[i],count);
    return 0;
}
 
