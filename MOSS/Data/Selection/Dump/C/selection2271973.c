#include<stdio.h>
static const int N =100;

void selectionSort(int *A, int n){
  int i,j,miji,key,count=0;
  for(i=0;i<n;i++){
    miji=i;
    for(j=i;j<n;j++){
      if(A[j]<A[miji])	miji=j;
    }
    key=A[i];
    A[i]=A[miji];
    A[miji]=key;
    if(miji!=i) count++;
  }
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
}

int main(){
  int n,i;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  selectionSort(A,n);

  return 0;
}
