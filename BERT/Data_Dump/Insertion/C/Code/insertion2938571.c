#include<stdio.h>

int main(){
  int i,j,k,n,v;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  
  for(k=0;k<n;k++){
    printf("%d",A[k]);
    if(k<n-1){
      printf(" ");
    }else{
      printf("\n");
    }
  }
  
  for(i=1;i<=n-1;i++){
    v=A[i];
    
    for(j=i-1;j>=0&&A[j]>v;j--){
      A[j+1]=A[j];
    }
    A[j+1]=v;
    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k<n-1){
	printf(" ");
      }else{
	printf("\n");
      }
    }
  }
  return 0;
}

