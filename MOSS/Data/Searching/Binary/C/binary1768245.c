#include<stdio.h>
#define N 100000
int binarySearch(int);
int n,q,S[N],T[N];
int main(){
  int i,j,count = 0,num;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }
  for(i = 0;i < q;i++){
  num = binarySearch(T[i]);
  if(num == 1)count++;
  }
   printf("%d\n",count);

  return 0;
}

int binarySearch(int key){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    }
    else if(key < S[mid]){
      right = mid;
    }
    else{
	  left = mid + 1;
    }
  }
    return 0;
	      
}
