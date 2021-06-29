#include<stdio.h>
int linearsearch(int[],int,int);
int main(){
  int i,j,n,x,key,count=0;
  int A[10000];
    scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&key);
    x=linearsearch(A,n,key);
    if(x!=n+1)count++;
  }
  printf("%d\n",count);
  return 0;
}
int linearsearch(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)i++;
  if(i==n)return n+1;
  else return i;
}

