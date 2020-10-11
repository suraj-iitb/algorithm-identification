#include<stdio.h>
int main(void){
  int i,j,n,len,c,count=0;
  int A[100];
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<len;i++){
    for(j=len-1;j>i;j--){
      if(A[j]<A[j-1]){
	c=A[j];
	A[j]=A[j-1];
	A[j-1]=c;
	count++;
      }
    }
  }
  for(i=0;i<len;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
