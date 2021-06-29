#include<stdio.h>
#define N 100

int main()
{
  int i,j,m,flag=1,count=0,tmp=0;
  int A[N];
  
  scanf("%d",&m);
  for(i = 0;i < m;i++){
    scanf("%d",&A[i]);
  }
  
  i = 0;
  
  while(flag){
    flag = 0;
    for(j = m-1;j >= i+1;j--){
      if(A[j] < A[j - 1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
	count++;
      }
    }
    i++;
  }
  
  for(i = 0;i < m-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[m-1]);
  printf("%d\n",count);
  
  return 0;
}
