#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int A[N],kazu,i,j,kou,minj,kari;

  scanf("%d",&kazu);
  if(kazu>100)exit(1);
  for(i=0;i<kazu;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<kazu;i++){
    minj=i;
    for(j=i;j<kazu;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
    kari=A[minj];
    A[minj]=A[i];
    A[i]=kari;
    kou++;
    }
  }
  for(i=0;i<kazu;i++){
    printf("%d",A[i]);
    if(i<kazu-1)printf(" ");
  }
  printf("\n%d\n",kou);

  return 0;
}

