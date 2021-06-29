#include<stdio.h>
#define N 100
int cnt=0;
void bubbleSort(int A[],int n){
  int flag=1,j,v;
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
        v=A[j];
        A[j]=A[j-1];
        A[j-1]=v;
        flag=1;
        cnt++;
      }
    }
  }for(j=0;j<n-1;j++){
    printf("%d ",A[j]);
  }printf("%d\n",A[n-1]);
}

int main(){
  int A[N],i,j,flag,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,n);
  printf("%d\n",cnt);
}

