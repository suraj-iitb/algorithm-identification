#include <stdio.h>
#include <string.h>
int n,S[1000000000];
int binarySearch(int key){
  int left=0,right=n+1,mid;
    while (left<right){
      mid=(left+right)/2;
      if(S[mid]==key){
        return 1;
      }else if(key<S[mid]){
        right=mid;
      }else if(key>S[mid]){
        left=mid+1;
      }
    }
      return 0;
}

int main(){
  int i,T,cnt=0,q;
  scanf("%d", &n);
  for ( i = 1; i <= n; i++){
     scanf("%d", &S[i]);
  }
  scanf("%d",&q);
  for ( i = 1; i <= q; i++){
    scanf("%d",&T);
   if(binarySearch(T)){
     cnt++;
     }
   }
   printf("%d\n",cnt);
    return 0;
  }

