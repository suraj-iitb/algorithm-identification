#include<stdio.h>

int main(){
  int tmp,i,minj,j,n,cnt=0;

  scanf("%d",&n);

  int A[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    cnt++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }else{
      printf("\n");
    }
  }
  printf("%d\n",cnt);
  return 0;
}

