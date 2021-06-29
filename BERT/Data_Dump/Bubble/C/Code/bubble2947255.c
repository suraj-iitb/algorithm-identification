#include<stdio.h>
int main(){
  int A[100],i,n,chg,j,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	count++;
	chg=A[j];
	A[j]=A[j-1];
	A[j-1]=chg;	
    }
  }
  }
    for(i=0;i<n;i++){
      if(i==n-1)printf("%d\n",A[i]);
      else printf("%d ",A[i]);
    }
    printf("%d\n",count);
  return 0;
}

