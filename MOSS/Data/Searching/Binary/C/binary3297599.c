#include<stdio.h>

#define N 100000
#define Q 100000

int BinarySearch(int*, int, int);

int main() {
  int S[N];
  int T[Q];
  int i,j,x,y,res,count = 0;

  scanf("%d",&x);
  for(i = 0; i < x; i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&y);
  for(i = 0; i < y; i++) {
    scanf("%d",&T[i]);
  }

  for(i = 0; i < y; i++) {
    res = BinarySearch(S,T[i],x);
    if(res != -1) {
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}

int BinarySearch(int *S, int a, int x) {
  int right = x,left = 0,mid;

  while(left < right) {
    mid = (left + right) / 2;
    if(S[mid] == a) {
      return mid;
    }else if(a < S[mid]) {
      right = mid;
    }else{
      left = mid + 1;
    }
  }
    return -1;
  }
				

  

  
  

