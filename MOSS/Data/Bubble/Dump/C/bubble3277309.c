#include<stdio.h>
int main(){

  int a,b,c,i,j,k,l,N,cnt=0;
  scanf("%d",&N);
  int A[N];
  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j-1]>A[j]){
	c=A[j];
	A[j]=A[j-1];
	A[j-1]=c;
	cnt++;
	  }
     
    }
    if(i==N-1){
      printf("%d\n",A[i]);
    }else printf("%d ",A[i]);
  }
 
  printf("%d\n",cnt);

  return 0;
}

