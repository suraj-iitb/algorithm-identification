#include<stdio.h>
int main(){
  int a,A[100],n,i,count=0,arr;
  scanf("%d",&a);
  for(n=0;n<a;n++){
    scanf("%d",&A[n]);
  }
  for(i=0;i<a;i++){
    for(n=0;n<a-1;n++){
      if(A[n]>A[n+1]){
	arr=A[n+1];
	A[n+1]=A[n];
	A[n]=arr;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n]);
  printf("%d\n",count);
  return 0;
}
