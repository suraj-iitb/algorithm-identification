#include<stdio.h>
#define N 100
main(){
  int key,A[N],j,i,n,a;
  scanf("%d",&n);
  for(i=0;i<n;i++){
   scanf("%d",&A[i]);
  }

  for(i=1;i<=n;i++){
    key = A[i];
    j=i-1;
     for(a=0;a<n-1;a++){
      printf("%d ",A[a]);
    }
     printf("%d\n",A[n-1]);
    while(j>=0 && A[j]>key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
  }
  return 0; 
}
