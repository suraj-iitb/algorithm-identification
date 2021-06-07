#include <stdio.h>

int search(int key, int S[], int n);

int main(){
  int n,q,key,i,count=0,S[100000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(key, S, n)){
      count++;
    }
  }
  printf("%d\n",count);
  
  return 0;
}

int search(int key, int S[], int n){
  int left,right,mid;
  left = 0;
  right = n;
  while(left<right){
    mid = (left+right)/2;
    if(S[mid]==key){
      return 1;
    }else if(key<S[mid]){
      right = mid;
    }else{
      left = mid+1;
    }
  }
  return 0;
}

