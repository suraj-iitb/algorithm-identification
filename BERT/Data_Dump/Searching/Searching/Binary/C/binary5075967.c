#include <stdio.h>
#define S 100000
#define T 50000
int binarysearch(int,int*,int);

int main(){
  int s[S],t[T];
  int m,n;
  int i,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",&s[i]); }
  
  scanf("%d",&m);
  for(i=0;i<m;i++){scanf("%d",&t[i]); }

  for(i=0;i<m;i++){if(binarysearch(t[i],s,n) )count++; }

  printf("%d\n",count);


return 0;
}

int binarysearch(int key,int s[],int n){
  int l,mid,r;
  l=0;
  r=n;
  while(l<r){
    mid=(l+r)/2;
    if(key<s[mid])r=mid;
    else if(key>s[mid])l=mid+1;
    else return 1;
  }

  return 0; 
}

