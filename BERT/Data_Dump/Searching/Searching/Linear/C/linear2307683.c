#include <stdio.h>
#define N 10000
#define M 500
int main(){
  int i,j,n,length,count=0,A[N],B[M];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&length);
  for(i=0;i<length;i++){
    scanf("%d",&B[i]);
  }
  
  for(i=0;i<length;i++){
    j=0;
    A[n]=B[i];
    while(A[j]!=B[i]){
      j++;
    }
    
      if(j!=n){
	count++;
      }
  }
  
  printf("%d\n",count);
  return 0;
}
