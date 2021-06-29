#include<stdio.h>

int main(){
  int n,q,i,j,count=0,true_count=0;
  scanf("%d",&n);
  int A[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  int B[q+1];
  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(A[j]==B[i]) count++;
    }
    if(count>=1) true_count++;  
    count=0;
  }
  printf("%d\n",true_count);
  return 0;
}


