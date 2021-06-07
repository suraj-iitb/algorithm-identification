#include<stdio.h>
#define N 100000

int func(int);
int a[N],n;

int main(){
  int i,j,q,cnt=0;
  int k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&k);
    if(func(k)) cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}

int func(int k){
  int l=0,r=n,m;
  a[n] = k;
  while(l < r){
    m = (l + r)/2;
    if(k == a[m]) return 1;
    if(k > a[m]) l = m + 1;
    else if(k < a[m]) r = m;
  }
  return 0;
}

