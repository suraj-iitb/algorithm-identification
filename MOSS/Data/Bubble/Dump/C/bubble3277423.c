#include <stdio.h>
int main(){
  int a,b,i,j,N,flag=0,count=0;
  
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i+=1){
    scanf("%d",&A[i]);
  }
  for(a=0;a<N;a+=1){
    for(j=N-1;a<j;j-=1){
      if(A[j]<A[j-1]){
	flag=A[j];
	A[j]=A[j-1];
	A[j-1]=flag;//A[j] と A[j-1] を交換
	count++;
      }
    }
    if(a==N-1){
    printf("%d\n",A[a]);
    }
    else printf("%d ",A[a]);
    }
  printf("%d\n",count);
    return 0;
  }
    

