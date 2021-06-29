#include <stdio.h>
void swap(int *,int *);
int main(){
  int n,i,j;
  int A[100];
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",&A[i]); }

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	count++;
      }

    }
  }

  for(j=0;j<n-1;j++){printf("%d ",A[j]);}
  printf("%d\n%d\n",A[j],count);//j=n-1
  
return 0;
}

void swap(int *x, int *y){
  int tmp;
  
  tmp=*x;
  *x=*y;
  *y=tmp;
}

