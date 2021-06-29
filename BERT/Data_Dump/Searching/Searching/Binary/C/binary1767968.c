#include<stdio.h>
#define N 100000
#define Q 50000
int binarySearch(int);

int s[N],n;

int main(){
  int t,q[Q],count=0;;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&s[i]);
  }
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&q[i]);
    if(binarySearch(q[i])==1){
      count++;
    }
  }
     printf("%d\n",count);
  return 0;
}

int binarySearch(int key){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid = (left+right)/2;
    if(s[mid]==key) return 1;
    else if(key<s[mid]) right= mid;
    else left = mid+1;
  }
  return 0;
}
