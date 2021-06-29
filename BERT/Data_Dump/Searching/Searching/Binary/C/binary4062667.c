#include <stdio.h>

int S[100000],n;

int bs(int key){
  int L=0,R=n,mid;

  while(L<R){
    mid=(L+R)/2;
    if(key == S[mid]) return 1;
    if(key > S[mid]) L=mid+1;
    else if(key<S[mid]) R=mid;
  }

  return 0;
}

int main(){
  int i,q,t,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(bs(t)) cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}

