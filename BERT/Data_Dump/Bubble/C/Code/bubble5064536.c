#include <stdio.h>

int main(){
  int flag=1,i,cnt1=0,cnt2=0,N,tmp,A[100],j;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  while(flag){
   flag=0; 
    for(j=N-1;j>=1;j--){
     if(A[j]<A[j-1]){
      tmp=A[j-1];
      A[j-1]=A[j];
      A[j]=tmp;
      flag=1;
      cnt1++;
     }  
    }
    cnt2++;
    if(cnt2>N) break;
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[N-1]);
  printf("\n%d\n",cnt1);

  return 0;
}  
