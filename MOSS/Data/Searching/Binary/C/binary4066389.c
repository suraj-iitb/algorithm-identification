#include <stdio.h>

#define NOT_FOUND -1

int binarysearch(int);

int S[100000],T[50000],n1,n2,kakunin[10000];

int main(){

  int i,j,count = 0;

  scanf("%d",&n1);

  for(i = 0; i < n1;i++) scanf("%d",&S[i]);

  scanf("%d",&n2);

  for(i = 0; i < n2 ; i++) scanf("%d",&T[i]);


  for(j = 0;j < n2;j++){
    i = binarysearch(T[j]);
    if(i != NOT_FOUND) count++;
  }


  printf("%d\n",count);

}

int binarysearch(int key){
  int left = 0,right = n1,mid;

  while(left < right){
    mid = (right + left) / 2;

    if(S[mid] == key) return mid;

    else if(key < S[mid]) right = mid;

    else left = mid + 1;

  }
  return NOT_FOUND;
}
