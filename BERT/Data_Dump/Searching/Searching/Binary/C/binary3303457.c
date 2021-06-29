#include<stdio.h>

int n,S[100000];

int search(int T);

int main(void)
{
  int q,T;
  int i, count = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T);
    
    if(search(T) == 1){
      count++;
    }
  }
  printf("%d\n",count);

  return 0;
}




int search(int T){
  int r;
  int l = 0;
  int m = 0;

  r = n;

  while(l < r){
    m = (r+l)/2;
    if(T > S[m]){
      l = m+1;
    } else if(T < S[m]){
      r = m;
    } else {
      return 1;
    }
  }
    
  return 0;
}

