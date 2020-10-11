#include<stdio.h>
int sum=0;
int main()
{
  int i,j,n,minj,buf;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  
  for(i=0;i<n;i++){
	minj=i;
	for(j=i;j<n;j++)if(A[j] < A[minj])minj=j;
	
	if(i!=minj){buf=A[i];A[i]=A[minj];A[minj]=buf;sum++;}
  }//i
  for(i=0;i<n;i++){printf("%d",A[i]);
	if(i==n-1)printf("\n");
	else printf(" ");}
  printf("%d\n",sum);
  return 0;
}

