#include<stdio.h>
int main(){
  int i,j,frag = 1,n,A[100],tmp,count = 0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  while(frag != 0){
    frag = 0;
    for(j = n - 1 ; j > 0 ; j--){
      if(A[j] < A[j - 1]){
	tmp = A[j];
	A[j] = A[j - 1];
	A[j - 1] = tmp;
	frag = 1;
	count += 1;
      }
    }
  }
  for(i = 0 ; i < n ; i++){
    if(i == n - 1)printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

