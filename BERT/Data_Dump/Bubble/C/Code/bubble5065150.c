#include<stdio.h>
#define NUM 100

void bubbleSort(int *,int);

int main(){

  int i,a[NUM],n,cnt;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  bubbleSort(a,n);

  return 0;
}

void bubbleSort(int *A,int n){
  int i,j,v,flag=1,cnt=0;
  i=0;
  while(flag == 1){
    flag = 0;
    for(j=n-1; j>=1; j--){
      if(A[j] < A[j-1]){
        v =A[j];
        A[j] = A[j-1];
        A[j-1] = v;
        flag = 1;
        i++;
        cnt++;
      }
    }
  }
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
    printf("%d\n",A[n-1]);
    printf("%d\n",cnt);
}


