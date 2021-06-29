#include<stdio.h>
#define MAX 10000

int search(int [],int,int);

int main() {
  
  int n,s[MAX],q,t[MAX],c=0;
  int i;
  
  // input
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);
  
  // Search
  for(i=0;i<q;i++){
    c += search(s,t[i],n);
  }
  printf("%d\n",c);
  
  
  return 0;
}

int search(int *s,int t,int n) {
  
  int i;
  
  for(i=0; i<n; i++){ 
    if( *(s+i) == t) return 1;
  }
  return 0;
}
