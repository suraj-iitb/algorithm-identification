#include <stdio.h>
#define N 100

int main(){
  int i,j,n,minj,cnt=0,tmp,A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++)
      if(A[j]<A[minj])
	minj=j;
    if(i!=minj){
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      cnt++;
    }
  }

  printf("%d",A[0]);
  for(i=1;i<n;i++)
    printf(" %d",A[i]);
  printf("\n%d\n",cnt);

  return 0;
}
