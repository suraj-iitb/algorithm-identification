#include <stdio.h>

int search(int *, int , int);

int main(){

int i,n,q,A[10000],key,sum = 0;

scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }

scanf("%d",&q);
for(i=0;i<q;i++){
  scanf("%d",&key);
  if(search(A, n, key) != n) sum++;
  }
  printf("%d\n",sum);

return 0;
}

int search(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while (A[i] != key) i++;
  return i;
}