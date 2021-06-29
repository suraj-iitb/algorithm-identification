#include<stdio.h>
int main()
{
  int i,j,u=0,m,temp=0,A[100],minj;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=m-2;i++){
    minj=i;
    for(j=i;j<=m-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj) u++;
  }
  for(i=0;i<m-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[m-1]);
  printf("\n");
  printf("%d\n",u);
  return 0;
}
