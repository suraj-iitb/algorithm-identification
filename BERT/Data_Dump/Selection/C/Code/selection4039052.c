#include <stdio.h>
int Y (int* ,int);
int count;
int main ()
{
  int i,n,hi[100];
  scanf ("%d",&n);
  for (i=0;i<n;i++){
    scanf ("%d",&hi[i]);
  }
  count=Y(hi,n);

  for (i=0;i<n;i++){
    printf ("%d",hi[i]);
    if (i!=n-1)
      printf (" ");
  }
  printf ("\n");
  printf ("%d\n",count);

  return 0;
}
int Y (int* A,int N){
  int i,j,minj,p,count=0;
  for (i=0;i<=N-1;i++){
    minj=i;
    for (j=i;j<=N-1;j++){
      if (A[j]<A[minj]){
	minj=j;
      }
    }
    /*交換*/
    if(i!=minj){
      p=A[i];
      A[i]=A[minj];
      A[minj]=p;
      count++;
    }
  }
  return count;
}

