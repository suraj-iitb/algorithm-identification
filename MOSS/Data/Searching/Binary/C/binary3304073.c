#include <stdio.h>

int a(int n,int A[],int key)
{

  int left, right, mid;

  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]){
      return mid;
    }
    if(key > A[mid]){
      left = mid + 1;
    }
    else if(key < A[mid]){
      right = mid;
    }
  }
  return -1;
}

int main()
{

  int count, n, q, i;

  count = 0;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    if(a(n,S,T[i]) != -1){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;

}




