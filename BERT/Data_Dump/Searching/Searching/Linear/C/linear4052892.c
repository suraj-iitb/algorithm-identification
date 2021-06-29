#include <stdio.h>

int search(int S[],int n,int key){
  int i;
  i=0;
  S[n]=key;
  while(S[i] != key)i++;
  return i !=n;
    }

int main(){
  int i,n,q,cnt=0,key;
  scanf("%d",&n);
  int S[10000];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
  if (search(S, n, key))cnt++;
}
  printf("%d\n",cnt);
  return 0;
}

