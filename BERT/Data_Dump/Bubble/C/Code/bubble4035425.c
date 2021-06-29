#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,A[100],f=0,temp,i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	f++;
      }
    }
  }
   for(i=0;i<N;i++){
     if(i!=N-1)printf("%d ",A[i]);
     else printf("%d",A[i]);
   }
   printf("\n%d\n",f);
   return 0;
}

