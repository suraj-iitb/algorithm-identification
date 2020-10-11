#include <stdio.h>

int X (int* ,int);
int count;
int main()
{
  int i,n,hi[100];
  scanf ("%d",&n);
  for (i=0;i<n;i++){
    scanf ("%d",&hi[i]);
  }
  count=X(hi,n);

  for (i=0;i<n;i++){
    printf ("%d",hi[i]);
    if (i!=n-1)
      printf (" ");
  }
  printf ("\n");
  printf ("%d\n",count);

  return 0;
}

int X (int* A,int N){
  int j,p,count=0;
  int flag;
  flag=1;
  while (flag==1){
    flag=0;
    for (j=N-1;j>=1;j--){
      if (A[j]<A[j-1]){
	/*交換*/
	p=A[j];
	A[j]=A[j-1];
	A[j-1]=p;
	flag=1;
	count++;
      }
      
    }
  }
  return count;
}

