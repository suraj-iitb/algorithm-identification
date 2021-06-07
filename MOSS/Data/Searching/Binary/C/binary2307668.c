#include <stdio.h>
#define Nmax 100000
#define Qmax 50000

int BinarySearch(int *,int,int );

int main(){
  int n,q,i;
  int T[Qmax], S[Nmax];
  int sum=0;
  int ans;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0 ; i<q ; i++){
    if(BinarySearch(S,T[i],n) == 1) sum++;
  }
  printf("%d\n",sum);

  return 0;
}

int BinarySearch(int *S,int key,int n){
  int left=0;
  int right;
  int mid;

  right = n;
  
  while(left < right){
    mid = (left + right) / 2;
    if (S[mid] == key) return 1;
    else if (key < S[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}
