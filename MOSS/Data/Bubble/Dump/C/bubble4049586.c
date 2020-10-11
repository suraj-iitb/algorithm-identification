#include <stdio.h>

int main(){
  int flag,n,i,j,tmp,cnt=0;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  flag = 1;
  while(flag==1){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cnt++;
	flag = 1;
      }
    }
  }
	
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],cnt);

  return 0;
}

