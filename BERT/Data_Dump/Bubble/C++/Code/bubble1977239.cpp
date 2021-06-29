#include<stdio.h>
main(){
  int i,j;
  int n,m;
  int A[100],cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j] < A[j-1]){
        m = A[j];
        A[j] = A[j-1];
        A[j-1] = m;
        cnt++;
       }
     }
   }
   for(i=0;i<n;i++){
     printf("%d",A[i]);
     if(i==n-1){
       printf("\n%d\n",cnt);
     }else{
       printf(" ");
     }
   }
}
