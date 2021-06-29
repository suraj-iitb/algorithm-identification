#include<stdio.h>

int main(){
  int n,q,count=0;

  scanf("%d",&n);
  int S[n],right=n,left=0,mid,i;
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    right=n;
    left=0;
    while(left < right){
      mid = (right + left)/2;
      if(S[mid] == T[i]){
        count++;
        break;
      }
      else if(T[i] < S[mid])
        right = mid;
      else left = mid + 1;
    }
  }

  printf("%d\n",count);

 return 0;
}

