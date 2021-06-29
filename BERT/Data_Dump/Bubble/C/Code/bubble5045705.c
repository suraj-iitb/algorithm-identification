#include<stdio.h>
#include<stdlib.h>

int bubble(int *,int);

int main(){
  int *A,n,i,num;

  /*入力*/
  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  num = bubble(A ,n);

  /*出力*/
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",num);

  return 0;
}

int bubble(int *A,int n){
  int j,k,c=0,flag=1;
  
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j] < A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	c++;
	flag = 1;
      }
    }
  }
  return c;
}
	  

