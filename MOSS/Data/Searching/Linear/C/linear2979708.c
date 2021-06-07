#include<stdio.h>
int linearSearch(int *,int,int);
int main(){
  int n,q,b,count=0;
  int A[10000];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&b);
    if(0 <= linearSearch(A,b,n))count++;
    }
  printf("%d\n",count);
  return 0;
}
int linearSearch(int *A,int b,int n){
  int i,NOT_FOUND=-1;
  
  for(i=0;i<n;i++){
    if(A[i]==b)return i;
    
  }
  return NOT_FOUND;
}

