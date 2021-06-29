#include <stdio.h>

#define N 1000000

int main(){

  int i;
  int j;
  int n;
  int q;
  int left;
  int right;
  int mid;
  int count=0;
  int s[N];
  int t[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }



  for(i=0;i<q;i++){
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid]==t[i]){
      count++;
      break;
    }
    else if(t[i] < s[mid]){
      right = mid;
    }
    else left = mid + 1;
   }
  }
   printf("%d\n",count);

   return 0;
}
