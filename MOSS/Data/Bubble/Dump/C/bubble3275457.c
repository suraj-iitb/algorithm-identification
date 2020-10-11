#include<stdio.h>
#define N 100
int main(){
  int n,A[N],i,j,v,count=0,b;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v)
      {
	A[j+1] = A[j];
	j--;
	count++;
      }
    A[j+1] = v;
  }
  for(b=0;b<n-1;b++) printf("%d ",A[b]); printf("%d",A[n-1]);
    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
  }

