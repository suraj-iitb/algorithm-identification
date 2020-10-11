#include<stdio.h>

int main(){
  int i,j,n,minj,a,c=0;
  int A[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
	a = A[i];
	A[i] = A[minj];
	A[minj] = a;
	if(i!=minj)c++;
   
  }

 for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",c);
  
  return 0;
}
  

