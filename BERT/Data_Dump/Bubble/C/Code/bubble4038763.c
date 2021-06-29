#include<stdio.h>
#define N 100
int main(){

  int i,j,a,A[N],k,count=0,flag;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  flag = 1; // 逆の隣接要素が存在する
  while(flag==1){
    flag = 0;
    for(j=a-1;1<=j;j--){
      if (A[j] < A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	flag = 1;
	count++;
      }
    }
  }
  for(k=0;k<a-1;k++)
  printf("%d ",A[k]);
  printf("%d",A[k]);
  printf("\n");
  printf("%d\n",count);
  

 
  return 0;
}

