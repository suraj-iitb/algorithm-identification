#include<stdio.h>

int main(){
  int i=0,j=0,n=0,count=0,temp;
  int minj;
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
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    count++;
    }

  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
printf("%d\n%d\n",A[n-1],count);
return 0;
}

