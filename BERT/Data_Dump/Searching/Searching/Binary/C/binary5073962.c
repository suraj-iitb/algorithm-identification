#include<stdio.h>
int Search(int,int);
int S[1000000];
int main()
{
  int i,n,q,count,key;
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Search(key,n)) count++;
  }

    printf("%d\n",count);

  return 0;
}

int Search(int key,int n)
{
  int l,r,m;
  l = 0;
  r = n;
  while(l < r){
    m = (l+r) / 2;
    if(key == S[m]) return 1;
    else if(key < S[m]) r = m;
    else if(key > S[m]) l = m + 1;
  }
  return 0;
}

