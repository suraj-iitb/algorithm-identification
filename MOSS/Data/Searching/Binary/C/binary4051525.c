#include<stdio.h>

#define SIZEN 100000

int main(){
  int n,S[SIZEN],q,t,i,count = 0,left = 0,right,mid;

  scanf("%d",&n);
  right = n;
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){
    scanf("%d",&t);
    left = 0; right = n;
    while(left < right){
      mid = (left + right)/2;
      if(t == S[mid]){
         count++;
         break;
       }
      if(t > S[mid]) left = mid+1;
      else if(t < S[mid]) right = mid;
    }
  }
  printf("%d\n",count);
  return 0;
}

