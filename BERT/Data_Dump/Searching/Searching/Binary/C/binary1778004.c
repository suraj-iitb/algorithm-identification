#include <stdio.h>
int S[100000];
int n;
int binarySearch(int[],int,int);

int main(){
  int count=0;
  int T[50000];
  int q,i;
  int re;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    count+=binarySearch(S,T[i],n);
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int S[],int key,int n){
  int mid=0;
  int left=0;
  int right=n;
   while(left<right){
     mid=(left+right)/2;
     if(S[mid]==key) return 1;
     else if(key<S[mid])
       right=mid;
     else
       left=mid+1;
   }
   return 0;
}
