#include <stdio.h> 

int main(){
  int N,i,j;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  trace(A,N);
  insert(A,N);

  return 0;
}

void trace(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

void insert(int a[],int n){
  int j,i,v;
  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    trace(a,n);
  }
}    
