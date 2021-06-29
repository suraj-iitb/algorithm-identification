#include<stdio.h>
#define N 100

void selection(int *,int);

int main(){

  int i,n,array[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&array[i]);


  selection(array,n);

  return 0;
}

void selection(int A[],int n){
  int i,j,cnt=0,minj,tmp;

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
    if(minj!=i)cnt++;
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cnt);
}

