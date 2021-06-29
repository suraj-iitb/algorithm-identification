#include <stdio.h>

int BinarySearch(int);
int S[100000],n;

int main(){
  int i,q,T,sum = 0;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T);
    if( BinarySearch(T) ) sum++;
  }
  
  printf("%d\n",sum);

  return 0;
}

int BinarySearch(int key){
  int left = 0;
  int right,mid;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    }
    else if(S[mid] < key){
      left = mid+1;
    }
    else if(S[mid] > key){
      right = mid;
    }
  }
  return 0;
}

