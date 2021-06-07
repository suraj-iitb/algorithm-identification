#include<stdio.h>

int linearSearch(int *, int, int);

int main(){
  int i,n,q,S[10000+1],key,cnt=0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    if(linearSearch(S, n, key)) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int linearSearch(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key) i++;
  return i != n;
}

