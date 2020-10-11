#include<stdio.h>

int main(){
  int n,i,j,c=0,t,frag;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  frag=1;
  while(frag){
    frag=0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
	c++;
	frag=1;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",c);
  return 0;
}

