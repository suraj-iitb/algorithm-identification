#include <stdio.h>
int main()
{
  int n,i,j,k,c,flag,key;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
  scanf("%d",&A[i]);

  flag=1;
  c = 0;

while(flag){
  flag=0;
  for(j=n-1;j>=1;j--){
    if(A[j]<A[j-1]){
        key=A[j];
        A[j]=A[j-1];
        A[j-1]=key;
        flag=1;
        c++;
      }
    }
}
for(i=0; i <= n-1;i++){
if(i != n-1) printf("%d ",A[i]);
else printf("%d\n",A[i]);
}
  printf("%d\n",c);
  return 0;
}

