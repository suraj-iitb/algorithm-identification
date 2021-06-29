#include <stdio.h>
#define N 100

void bubbleSort(int *,int);

int a=0;

int main(){
  int i,A[N],n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",a);
  return 0;
}

void bubbleSort(int *A,int n){
  int flag,i,j,s;
  flag=1;
  i=0;
  while(flag==1){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        s=A[j];
        A[j]=A[j-1];
        A[j-1]=s;
        flag=1;
        a++;
      }
    }
    i++;
  }
}

