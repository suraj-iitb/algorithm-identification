#include<stdio.h>
int input(int[]);
int isMatch(int[], int[], int, int);
int binarySearch(int, int[], int);
int S[100000], T[50000];

main(){
  int n, q;

  n = input(S);
  q = input(T);
 
  printf("%d\n", isMatch(S, T, n, q));
  return 0;
}

int input(int array[]){
  int i, e;
  scanf("%d", &e);
  for(i = 0; i < e; i++){
    scanf("%d", &array[i]);
  } 
  return e;
}

int isMatch(int S[], int T[], int n, int q){
  int count = 0, i;

  for(i = 0; i < q; i++){
    count += binarySearch(T[i], S, n);
  }
  return count;
}

int binarySearch(int key, int S[], int right){
  int mid, left;
  left = 0;
  while(left < right){
    mid = (right + left) / 2;
    if(key == S[mid]){
      return 1;
    } else if(key > S[mid]){
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return 0;
}
