#include<stdio.h>
#include<stdlib.h>

int A[2000001],B[2000001];

main(){
  int i,j,k,n,C[10001];
  k = 10000;

  scanf("%d",&n);
  i=1;
  while(i<n+1){
    scanf("%d",&A[i]);  
    i++;  
  }

  for(i=0;i<=k;i++){
    C[i] = 0;
  }
  for(j=1;j<n+1;j++){
    C[A[j]]++;
  }
  for(i=1;i<k+1;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=n;j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n)printf(" ");
    else printf("\n");  
  }

 return 0;
}
