#include<stdio.h>
int  linear(int , int [], int );
#define N 10000
int main() {
  int n,q,A[N+1],key,sum = 0,i;

  scanf("%d",&n);
for(i=0;i<n;i++)  scanf("%d", &A[i]);
  scanf("%d", &q);

for(i=0;i<q;i++) {
    scanf("%d", &key);
    if(linear(key,A,n)) sum++;
}
  printf("%d\n",sum);

  return 0;
}

int  linear(int key, int A[],int n) {
  int i = 0;
   A[n] = key;
   while(A[i] != key) i++;
  return i != n;
}
