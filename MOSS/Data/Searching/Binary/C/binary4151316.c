#include<stdio.h>

int n,S[1000000000];

int binary(int key){
  int left = 0;
  int right = n;
  

  while(left < right){
    int mid = (left + right) / 2;
    if(S[mid] == key ){
      return mid;
    }
    else if(key < S[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
    return -1;
}


int main(){

  int q,key,i,count=0;

  scanf("%d",&n);
  if(n > 100000) return 0;

  for(i = 0;i<n;i++){
    scanf("%d",&S[i]);

  }

  scanf("%d",&q);
  if(q> 50000) return 0;

  for(i = 0;i<q;i++){
    scanf("%d",&key);

    if(  binary(key) != -1){
      count++;
    }
  }
  printf("%d",count);
  printf("\n");

  return 0;

}
