#include<stdio.h>
#define N 100000

int func(int [],int,int);

int main(){
  int i,j,n,q,cnt=0;
  int a[N + 1];
  int k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&k);
    if(func(a,n,k)) cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}

int func(int a[], int n, int k){
  int i = 0;
  a[n] = k;
  while(a[i] != k){
    i++;
  }
  return i != n;
}

