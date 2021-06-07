#include<stdio.h>
#define N 10000
#define Q 500

int  linearSearch(int);
  int n,s[N];  
int main(){
  int i,q,l,cnt = 0;
  int t[Q];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
      scanf("%d",&s[i]);
  }
  scanf("%d",&q);

  for(i=0;i<q;i++){
      scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
  l = linearSearch(t[i]);
  if(l > 0) cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}
  
int  linearSearch(int key){
  int i = 0;

  s[n] = key;
  while(s[i] != key){
    i++;
    if(i == n) return 0;
  }
  return 1;
}
  
  
  
