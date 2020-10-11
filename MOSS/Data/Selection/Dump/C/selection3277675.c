#include <stdio.h>
#define N 100

int main(){
  int i,j,mini,A[N],t,n,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    t=A[i];A[i]=A[mini];A[mini]=t;
    if(i!=mini) cnt++;
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}

