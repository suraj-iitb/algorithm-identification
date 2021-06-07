#include <stdio.h>

int binarySearch(int);
int n,S[100000];
int main(){
  int q,i,j,T[100000],k=0,r;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    r=binarySearch(T[i]);
    if(r!=-1) k++;
  }

  printf("%d\n",k);
  return 0;
}

int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid;
  while (left < right){
    mid = (left + right) / 2;
    if (S[mid] == key)
      return mid;
    else if (key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return -1;
}
