#include<stdio.h>
int search(int *A,int n,int key);

  int main(){
  int n,q,A[10000],i,j,key,goukei=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(A,n,key))goukei++;
  }
  printf("%d\n",goukei);

  return 0;
}

int search(int A[],int n,int key){
  int k=0;
  A[n]=key;
  while(A[k]!=key)k++;
  return k!=n;
}
