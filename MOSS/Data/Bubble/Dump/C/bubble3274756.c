#include<stdio.h>
#define N 100
int main(){
  int n,A[N],i,j,hoge,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	sum++;
	hoge=A[j];
	A[j]=A[j-1];
	A[j-1]=hoge;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i!=0)
      printf(" ");
    printf("%d",A[i]);
      }
  printf("\n%d\n",sum);
  return 0;
}
