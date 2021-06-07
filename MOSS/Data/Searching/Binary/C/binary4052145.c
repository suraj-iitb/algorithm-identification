#include <stdio.h>
#define N 100000
#define Q 50000

int search(int *a,int key,int n);

int main(){
  int i,j,n,q,key,con = 0;
  int s[N],t[Q];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
    key = t[i];
    con += search(s,key,n);
  }
  printf("%d\n",con);
}

int search(int *a,int key,int n){
  int mid,left = 0,right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == key) return 1;
    else if(key < a[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

