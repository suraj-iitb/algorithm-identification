#include <stdio.h>

static const int N = 100;
int c=0;

void BubbleSort(int A[],int n){
  int i,j,temp;
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	c++;
      }
    }
  }
}

main(){
  int i,j,n;
  int A[N+1];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  BubbleSort(A,n);

  for(j=1;j<=n;j++){
    if(j>1) printf(" ");
    printf("%d",A[j-1]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
