#include <stdio.h>
#define N 100
int main(){
  int A[N],n,i,j,key,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	key = A[j];
	A[j]=A[j-1];
	A[j-1]=key;
	cnt++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",cnt);
    return 0;
}

