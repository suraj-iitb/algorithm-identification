#include<stdio.h>
int s[100000];
int binarySearch(int,int);

int main(){
  int n,q,i,t,kazu=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarySearch(t,n)) kazu++;
  }
  printf("%d\n",kazu);
  
  return 0;
}
int binarySearch(int key,int n){
  int mid,left=0,right=n;

  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==key) return 1;
    else if(key<s[mid]) right=mid;
    else left =mid+1;
  }
  return 0;
}

