#include<stdio.h>
#define N 100

int main(){
  int A[N],a,i,j,n,count=0,minj;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){      
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
	a=A[i];
	A[i]=A[minj];
	A[minj]=a;
	count++;	
    }
    
  }
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
