#include<stdio.h>
int linearSearch(int);

int n,S[10000],T[500];

int main(){
  int i,q,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    if((linearSearch(T[i]))==1)cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}

int linearSearch(int key){
  int i;
  for(i=0;i<n;i++){
    if(S[i]==key)return 1;
  }
  return 0;
}
