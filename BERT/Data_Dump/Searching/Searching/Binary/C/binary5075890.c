#include <stdio.h>
#include <stdlib.h>

int serch(int n,int *s,int key){
  int left = 0;
  int right = n;
  while(left < right){
    int mid = (left + right)/2;
    if(s[mid] == key){
      return 1;
    }else if(key > s[mid]){
      left = mid + 1;
    }else if(key < s[mid]){
      right = mid;
    }
  }
  return 0;
}

int main(){
  int n;
  scanf("%d",&n);
  int *s;
  s = (int *)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }
  int q;
  scanf("%d",&q);
  int *t;
  t = (int *)malloc(q * sizeof(int));
  for(int i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }

  int ans = 0;
  for(int i = 0; i < q; i++){
    ans += serch(n,s,t[i]);
  }
  printf("%d\n",ans);
}

