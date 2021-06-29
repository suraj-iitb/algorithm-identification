#include<stdio.h>


#define NOT_FOUND -1
#define MAX 100000

int binarysearch(int);

int S[MAX], n;

int main(){
  int T[MAX];
  int a=0,i,k;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&k);

  for(i = 0 ; i < k ; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0 ; i < k ; i++){
    if(binarysearch(T[i])!=NOT_FOUND)a++;
  }
  
  printf("%d\n",a);
}

int binarysearch(int key){
  int left=0,right=n,mid;

  while(left < right){
    
    mid = (left + right) / 2;

    if(S[mid] == key)return mid;

    else if(key < S[mid]) right = mid;

    else left = mid + 1;
  }

  return NOT_FOUND;
}

