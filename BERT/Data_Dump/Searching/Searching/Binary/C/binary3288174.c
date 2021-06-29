#include<stdio.h>
int binarySearch(int *,int,int);
int main(){
  int n,q;
  int S[1000001],T[50001];
  int ans;
  int i;
  ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    if(binarySearch(S,T[i],n)) ans++;
  }
  printf("%d\n",ans);
  return 0;
}

int binarySearch(int T[],int key,int n){
  int left = 0;
  int right = n;
  int mid;
  while(left<right){
    mid = (left + right)/2;
    if(T[mid] == key) return 1;
    else if(T[mid] > key) right = mid;
    else left = mid + 1;
  }
  return 0;
}

