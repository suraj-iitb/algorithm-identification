#include<stdio.h>
void selectionSort(int*,int);
int main(){
  int n,i,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);
  return 0;
}
void selectionSort(int*A,int n){
  int i,j,minj,b,c=0,flag;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(minj==i)c--;
    b=A[i];
    A[i]=A[minj];
    A[minj]=b;
      c++;
  }
  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",c);
}

