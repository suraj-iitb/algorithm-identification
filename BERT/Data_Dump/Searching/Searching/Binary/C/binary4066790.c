#include<stdio.h>
#include<stdlib.h>
#define M 1000000
int lub(int ,int ,int ,int *);


int main(){
  int n,m,A[100010],k=0,i;
  scanf("%d",&n);
 
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&m);
  
  while(m--){
    scanf("%d",&i);
    if(A[lub(0,n-1,i,A)]==i)k++;
  }
  printf("%d\n",k);
  return 0;
}


int lub(int l,int r,int n,int *A){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=A[m]?lub(l,m,n,A):lub(m+1,r,n,A);
}

