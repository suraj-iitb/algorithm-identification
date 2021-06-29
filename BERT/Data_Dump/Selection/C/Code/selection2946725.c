#include<stdio.h>
int main(){
  int dum,n,i,j,minj,ct;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(i!=minj)ct++;
      dum = A[i];
      A[i]=A[minj];
      A[minj]=dum;
      
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
      }
  printf("%d\n",A[n-1]);
  printf("%d\n",ct);
  return 0;
}

