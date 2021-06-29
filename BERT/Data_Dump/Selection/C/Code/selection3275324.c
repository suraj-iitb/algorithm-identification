#include <stdio.h>

int main(){
  int i,j,N,z,miji,count=0,A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
 }
  for(i=0;i<N-1;i++){
    miji=i;
    for(j=i;j<N;j++){
      if(A[j]<A[miji]){
	miji=j;
      }
	
    }
    if(miji!=i){
        z=A[miji];
	A[miji]=A[i];
	A[i]=z;
	count++;
    }
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n%d\n",count);


  return 0;
}

