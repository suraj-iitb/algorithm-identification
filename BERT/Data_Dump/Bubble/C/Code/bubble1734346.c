#include <stdio.h>
#define N 100
int main(){
  int n,i,j,count=0;
  int A[N];
  int flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){  
scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	flag=A[j];
        A[j]=A[j-1];
	A[j-1]=flag;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}
