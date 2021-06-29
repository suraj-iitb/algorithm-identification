#include<stdio.h>
#define N 100


void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}



int main(){
  int n,i,j,flag=1,k=0,kaunt=0;//k=hozon
  int A[N];

  scanf("%d",&n);
  for(i =0;i<n;i++)scanf("%d",&A[i]);

  while(flag){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	flag = 1;
	kaunt++;	
      }
    }
  }

  

  trace(A,n);
  printf("%d\n",kaunt);
  
  return 0;
}
