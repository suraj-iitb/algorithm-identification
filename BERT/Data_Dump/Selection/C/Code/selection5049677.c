#include <stdio.h>
int main(){
int i,j,n,count=0,minj,tmp;
scanf("%d",&n);
int A[n];
  for(i=0;i<n;i++)  scanf("%d",&A[i]);

  for(i=0;i<n-1;i++){
  minj=i;
  for(j=i;j<=n-1;j++){
    if(A[j]<A[minj]) minj=j;
  }
  if(i!=minj){
  tmp=A[i];
  A[i]=A[minj];
  A[minj]=tmp;
  count++;
}
  }
  for(j=0;j<n;j++){
      printf("%d",A[j]);
      if(j<n-1)  printf(" ");
    }
    printf("\n%d\n",count);
  return 0;
}

