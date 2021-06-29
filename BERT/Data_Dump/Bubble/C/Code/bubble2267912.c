#include<stdio.h>
#define N 100


int main(){
  int i,j,n,num=0,tmp,A[N];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }

 for(i=0 ; i<n-1 ; i++){
    for(j=n-1 ; j>i ; j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	num++;
      }
    }
  }
  for(i=0 ; i<n ; i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
   
  }
  
  printf("\n");
  printf("%d\n",num);

  return 0;
}
