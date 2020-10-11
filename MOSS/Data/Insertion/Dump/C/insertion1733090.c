#include<stdio.h>
int main()
{
  int A[100],i,j,v,N,x;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
        if(i==N-1) printf("%d\n",A[i]);
      else printf("%d ",A[i]);
  }
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(x=0;x<N;x++){
      if(x==N-1) 
	printf("%d\n",A[x]);
      else printf("%d ",A[x]);
    }
  }
  return 0;
}
