#include <stdio.h>
#define MAX 100000

int binarySearch(int,int);
int S[MAX];

int main(){

  int i,n,q,T,kosu=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&T);
    if(binarySearch(T,n)==1) kosu++;
     }
  printf("%d\n",kosu);

  return 0;
}

int binarySearch(int key,int n){

  int i=0,left=0,right=n,mid;

  while(left < right){
    mid = (left + right) / 2;
    if (S[mid] == key)
      return 1;
	    else if (key < S[mid])
	      right = mid;
        else
	  left = mid + 1;
  }
  return 0;
}

