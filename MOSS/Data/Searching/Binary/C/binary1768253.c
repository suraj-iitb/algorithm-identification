#include <stdio.h>

int binarySearch(int);

int S[100000];
int n;

int main(){

  int q,key,count=0,flag=0,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&key);
      flag = binarySearch(key);
    if(S[flag] == key){
      count++;
    }
  }
  
  printf("%d\n",count);

  return 0;
}


int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid = 0;
  
  
  while(left<right){
    mid = (left + right)/2;
    if(S[mid] == key)return mid;
    else if(key < S[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}
