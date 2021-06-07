#include <stdio.h>

int S[100000];
int T[50000];

int binarySearch(int length , int key){
  int left = 0;
  int right = length ;
  int mid;

  while(left < right){
    mid = (left + right)/2;
    if(key == S[mid]){
      return 1;
      break;
    }
    else if(key > S[mid])left = mid + 1;
    else if(key < S[mid])right = mid;
  }

  return 0;
}

int main(){

  int i;
  int n,q;
  int ansCounter = 0;
  int tof;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T[i]);
  }


for(i = 0 ; i < q ; i++){
  tof = binarySearch(n ,T[i]);
  if (tof == 1)ansCounter++;
}

printf("%d\n",ansCounter);

return 0;
}

