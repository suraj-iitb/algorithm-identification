#include<stdio.h>

int bubbleSort(int A[] ,int n){
  int j,v;
  int sw=0;
  int flag = 1;
  while (flag){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
	v=A[j-1];
	A[j-1]=A[j];
	A[j]=v;
	flag = 1;
	sw++;
      }
    }
  }
  return sw;
}
int main(){
  int i,n,sw;
    int A[100];
    scanf("%d",&n);
    for(i = 0;i<n;i++){
      scanf("%d",&A[i]);
    }
    sw =bubbleSort(A,n);
    for(i = 0;i < n; i++)
  {
    printf("%d",A[i]);
    if(i != n-1)
    printf(" ");
  }
    printf("\n");
    printf("%d\n",sw);
     
    return 0;
}
    

