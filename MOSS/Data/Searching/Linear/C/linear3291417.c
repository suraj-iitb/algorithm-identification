#include<stdio.h>
#include<stdlib.h>

int linearSearch(int, int [], int);

int main(){
  int n,q,i,key,count=0;
  int S[100001];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&key);
    if(linearSearch(n, S, key) != -1) count++;
  }

  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int n, int A[], int key){
  int i=0;

  A[n] = key;

  while(A[i] != key) i++;
  if(i == n) return -1;
  else return i;
}

