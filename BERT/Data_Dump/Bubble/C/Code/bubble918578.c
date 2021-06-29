#include <stdio.h>

main(){
  int i,j,n,A[100],tmp,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
     count++;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }
    //  else if(i=n-1)break;
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
