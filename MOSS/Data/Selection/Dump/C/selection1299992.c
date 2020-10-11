#include<stdio.h>
int main(){
  int i,j,miji,n,temp,count=0,A[100];
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    miji=i;
  for(j=i;j<=n-1;j++){
    if(A[j] < A[miji]){
      miji = j;
    }
  }
      temp = A[i];
      A[i] = A[miji];
	A[miji] = temp;
	if(i != miji)	count++;
    }
    
  
  
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);

  return 0;
}
