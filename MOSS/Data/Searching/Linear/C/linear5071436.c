#include<stdio.h>
#define NOT_FOUND -1
int linearSearch(int *,int,int);

int main(){
  int i,n,q,A[10000],sum=0,key;

  scanf("%d\n",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d\n",&q);

  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(A,n,key)!=NOT_FOUND) sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int linearSearch(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  if(i==n) return NOT_FOUND;
  else return i;
}
