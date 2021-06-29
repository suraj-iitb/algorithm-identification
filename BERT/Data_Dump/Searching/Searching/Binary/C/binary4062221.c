#include<stdio.h>
#define MAX 10000000

int S[MAX], T[MAX];
int n;

int binarySearch(int key){
  int left = 0;
  int right = n;

  while(left < right){
      int mid = (left + right)/2;
      if(S[mid] == key){
          return mid;
      }else if(key < S[mid]){
          right = mid;
      }else{
          left = mid + 1;
      }
   
  }
     return -1;
}

int main(void){
  int i, q, a;
  int count = 0;

  scanf("%d\n", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d\n", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for (i = 0; i < q; i++) {
    a = binarySearch(T[i]);
    if(a >= 0){
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}

