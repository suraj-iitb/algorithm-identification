
#include<stdio.h>
int main()
{
  int i,j,u=0,m,temp=0,A[100];
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<m-1;i++){
    for(j=m-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	u++;
      }
    }
  }
  for(i=0;i<m-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[m-1]);
  printf("\n");
  printf("%d\n",u);
  return 0;
}
