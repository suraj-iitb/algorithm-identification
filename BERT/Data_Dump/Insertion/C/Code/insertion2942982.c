#include<stdio.h>
#define N 100
int main(){
  int i,j,n,k,key;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    for(k=0;k<n;k++){
      if(k!=n-1) printf("%d ",A[k]);
      else printf("%d\n",A[k]);
    }
  }
  return 0;
}



