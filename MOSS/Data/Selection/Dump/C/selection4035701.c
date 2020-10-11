#include <stdio.h>

int main()
{
  int i,j,n,a,cnt,m;
  scanf("%d",&n);
  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    m=i;
      for(j=i+1;j<n;j++){
	if(A[j]<A[m])m=j;
      }
    if(A[i]>A[m]){
      int c=A[i];
      A[i]=A[m];
      A[m]=c;
      cnt++;
    }
  }
  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }

  printf("\n%d\n",cnt);

  
  return 0;
}

