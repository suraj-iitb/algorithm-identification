#include<stdio.h>

int main(){
  int n,i,j,c;
  int flag=1,a=0;
  int A[100];
  
 scanf("%d",&n);

for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  

  
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	c = A[j];
	A[j] = A[j-1];
	A[j-1] = c;
	flag = 1;
	a++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",a);
  
  return 0;
}

