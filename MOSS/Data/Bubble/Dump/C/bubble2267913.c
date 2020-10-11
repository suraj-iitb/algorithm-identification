#include<stdio.h>

#define N 100

int main(){
  int i,n,A[N],j,tmp,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<n; i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	cnt++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);

  return 0;
}
