#include <stdio.h>

int linerSearch(int);
int n,S[10000];
int main(){
  int q,i,j,T[10000],k=0,r;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    r=linerSearch(T[i]);
    if(r!=-1) k++;
  }

  printf("%d\n",k);
  return 0;
}

int linerSearch(int key){
  int i;
  for(i=0;i<n;i++){
    if(S[i]==key) return i;
  }
  return -1;
}
