#include <stdio.h>

int binarySearch(int *,int ,int );

int main(){

int i,n,q,A[100000],T[50000],sum=0,key;

scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }

scanf("%d",&q);
for(i=0;i<q;i++){
  scanf("%d",&T[i]);
  key = T[i];
  if(A[binarySearch(A,n,key)] == T[i]) sum++;
  }
  printf("%d\n",sum);

return 0;
}

int binarySearch(int A[],int n,int key){
int left = 0, right = n,mid;

while(left < right) {
  mid = (left + right)/2;
  if (A[mid] == key) return mid;
  else if (key < A[mid]) right = mid;
  else left = mid + 1;
}
  return -1;
}
