#include <stdio.h>
#define N 100

#include <stdio.h>

int main() {

  int i,j,a=0;
  int  A[N],flag;
  int p,n,minj;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<=n-1;i++){
    minj=i;
    flag=0;
    for(j=i; j<=n-1; j++){
      if(A[j]<A[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
      p=A[i];
      A[i]=A[minj];
      A[minj]=p;
      a++;
    }
  }
  for(i = 0; i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)  printf(" ");
  }
  printf("\n%d\n",a);
  return 0;
}

