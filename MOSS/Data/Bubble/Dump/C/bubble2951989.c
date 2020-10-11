#include <stdio.h>
int main(){
  int i,j,k,tmp,A[100],n,count=0;

scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
}

for(i=0;i<n-1;i++){
  for(j=n-1;j>i;j--){
    if(A[j]<A[j-1]){
      tmp = A[j];
      A[j] = A[j-1];
      A[j-1] = tmp;
      count++;
    }
    }
  }

  for(k=0;k<n-1;k++){
    printf("%d ",A[k]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}
