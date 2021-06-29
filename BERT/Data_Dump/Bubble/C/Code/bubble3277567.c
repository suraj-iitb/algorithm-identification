#include <stdio.h>
#define N 100
int main(){
  int i,j,A[N],n,flag,t,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(i=0;i<n-1;i++){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	t=A[j];A[j]=A[j-1];A[j-1]=t;
	flag=1;
	cnt++;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}
	
  

