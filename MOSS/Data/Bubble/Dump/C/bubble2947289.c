#include<stdio.h>
void bubbleSort(int*,int); //(A[100],n)
int main(){
  int n,A[100];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }
  bubbleSort(A,n);
  return 0;
}
void bubbleSort(int *A,int n){
  int i,flag=1,b,c=0;
  while(flag==1){
    flag=0;
    for(i=n-1;0<i;i--){
      if(A[i]<A[i-1]){
	b=A[i];
	A[i]=A[i-1];
	A[i-1]=b;
	flag=1;
	c++;
      }
    }
  }
    printf("%d",A[0]);
    for(i=1;i<n;i++){
      printf(" %d",A[i]);
    }
    printf("\n%d\n",c);
}

