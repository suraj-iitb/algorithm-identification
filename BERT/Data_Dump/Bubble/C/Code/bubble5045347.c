#include<stdio.h>

int main(){
  int a,b,i,j,k,n,flag,s;
  int cnt=0;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j=n-1;j>=1;j--){
	    if( A[j] < A[j-1]){
	    s=A[j];
	     A[j]=A[j-1];
	    A[j-1]=s;
	    flag = 1;
	    cnt++;
    	}
    }  
  }
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",A[i]);
    }
    else{
      printf("%d ",A[i]);
    }
  }
  printf("%d\n",cnt);
}

