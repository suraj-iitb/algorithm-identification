#include <stdio.h>
int S[100000000];
int T[100000000];
int s,t;
int serch(int);
int main(){
  int i=0,count=0;
  scanf("%d",&s);
  while(i<s){
    scanf("%d",&S[i]);
    i++;
  }
  i=0;
  scanf("%d",&t);
  while(i<t){
    scanf("%d",&T[i]);
    i++;
  }
  for(i=0;i<t;i++) count+=search(T[i]);
  printf("%d\n",count);
  return 0;
}

int search(int x){
  int l=0,r=s,m;
  while(l<r){
    m=(l+r)/2;
    if(S[m]==x) return 1;
    else if(x<S[m]) r=m;
    else l=m+1;
  }
  return 0;
}
