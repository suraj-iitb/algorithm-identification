#include <stdio.h>

#define S_MAX 200000
#define T_MAX 100000

int search(int);

int S[S_MAX], T[T_MAX];
int n, q;

int main(){
  int i, num = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0 ; i < q ; i++){
    if(search(i) == 0)num++;
  }

  printf("%d\n", num);
  
  return 0;
}

int search(int i){
  int left = 0, right = n, mid;

  while(left != right){
    mid = (left + right) / 2;
    if(S[mid] > T[i]){
      right = mid;
    }else if(S[mid] < T[i]){
      left = mid + 1;
    }else{
      return 0;
    }
  }

  return 1;  
}

