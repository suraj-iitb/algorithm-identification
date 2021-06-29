#include <stdio.h>
int binarySearch(int S[], int n, int key){
  int left=0, right=n;
  int mid;
  while(left<right){
	mid=(left+right)/2;
	if(S[mid]==key)
	  return 1;
	else if(S[mid]<key)
	  left=mid+1;
	else 
	  right=mid;
  }
  return 0;
}

int main(){
  int n, q;
  int S[100005];
  int i, j;
  int count=0;
  int key;
  scanf("%d", &n);
  for(i=0; i<n; ++i){
	scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; ++i){
	scanf("%d", &key);
	count+=binarySearch(S, n, key);
  }
  //
  printf("%d\n", count);
  return 0;
}

