#include<stdio.h>

int n;
int s[100000];

int Binary(int a){
  int L = 0;
  int C = 0;
  int R = n;
  while(R > L){

  C = (L + R)/2;

  if(a == s[C]){
    return 1;
  }
  else if(a < s[C])
    R = C;
  else if(a > s[C])
    L = C + 1;
  }
  return 0;
}



int main(){

int a, q, i, j, ans = 0;


  scanf("%d", &n);
for(i = 0; i < n; i++){
  scanf("%d", &s[i]);
}

  scanf("%d", &q);
for(i = 0; i < q; i++){
  scanf("%d", &a);
  if(Binary(a) == 1)
    ans++;
}

  printf("%d\n", ans);

  return 0;
}
