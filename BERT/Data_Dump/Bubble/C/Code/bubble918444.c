#include <stdio.h>

void swap(int,int);
int A[100],c=0;

main(){
  int i,j,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]) swap(j,j-1);

    }
  }

  for(i=0;i<n;i++){
    if(i==n-1) {
      printf("%d",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("\n%d\n",c);

  return 0;
}

void swap(int x,int y){
  int tmp;

  tmp=A[x];
  A[x]=A[y];
  A[y]=tmp;

  c++;
}
