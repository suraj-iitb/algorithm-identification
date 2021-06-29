#include <stdio.h>
int main()
{
  int n,i,j,k,l,minj,key;
  int A[100];
  int c=0;

  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
  scanf("%d",&A[i]);


for(i=0;i<n-1;i++){
  minj = i;
  for(j=i;j<=n-1;j++){
    if(A[j]<A[minj]){
      minj = j;
    }
  }
  if(minj!=i){
  key=A[i];
  A[i]=A[minj];
  A[minj]=key;
  c++;
}
}

  for(i=0; i <= n-1;i++){
  if(i != n-1) printf("%d ",A[i]);
  else printf("%d\n",A[i]);
  }
    printf("%d\n",c);
  return 0;
}

