#include<stdio.h>
#include<stdlib.h>

#define MAX 100001
#define NOT -1;

int s[MAX],n;

int binarySearch(int t){
  int l,r,mid;
  l = 0;
  r = n;
  while(l < r){
    mid = (l+r)/2;
    if(s[mid] == t)return 1;
    else if(t < s[mid])r = mid;
    else l = mid +1;
  }
  return NOT;
}

int main(){
  int q,sum=0;
  int t;
  int i,j;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t);
    j = binarySearch(t);
    if(j != -1)sum++;
  }


  printf("%d\n",sum);
  return 0;
}

