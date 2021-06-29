#include<stdio.h>

int linerSearch(int A[], int n, int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)
    i++;
  return i;
}

int main(){
  int i=0, n, A[10000], q, key, sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if((linerSearch(A,n,key))!=n)
      sum++;
  }
  printf("%d\n",sum);
  return 0;
}

