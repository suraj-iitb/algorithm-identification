#include<stdio.h>

int main(){
  int a,b,i,j,flag,n,minj,s;
  int cnt=0;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    minj=i;
    flag=0;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	 minj=j;
	 flag=1;
      }
    }
    
    if(flag==1){
      cnt++;
    }
    s=A[i];
    A[i]=A[minj];
    A[minj]=s;
      
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
