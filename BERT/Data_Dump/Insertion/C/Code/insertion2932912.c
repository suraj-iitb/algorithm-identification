#include<stdio.h>
#define N 100
int main(){
  int n;
  int a[1000];
  int i,j,v,c;
  while(1){
    scanf("%d",&n);
    if(n<=N && 1<=n) break;
  }
  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }
  for(i=1 ; i<=n ;i++){
    for(c=0 ; c< n ; c++){
      if(c<n-1) printf("%d ", a[c]);
      else printf("%d\n", a[c]);
    }
    v = a[i];
    j = i-1;
    while(j>=0 && a[j] >v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
}

