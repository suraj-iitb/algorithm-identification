#include<stdio.h>

int main(){
  int i,j,f,N,b,s,count;
  f=1;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  count=0;
  i=0;
  while(f){
    f=0;
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	b=A[j];
	A[j]=A[j-1];
	A[j-1]=b;
	f=1;
	count++;
      }
    }
    i++;
  }
  for(s=0;s<=N-1;s++){
    if(s<N-1)
      printf("%d ",A[s]);
    else printf("%d\n",A[s]);
  }
  printf("%d\n",count);
	 
  return 0;
}
  
  

