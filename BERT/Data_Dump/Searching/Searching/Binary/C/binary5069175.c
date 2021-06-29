#include <stdio.h>

int main()
{
  int n,S[100000],q,T[50000],i,c=0,p,mid,right,left;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    p = T[i];
    left = 0;
    right = n;
    while(right - left >= 2){
      mid = (left + right) / 2;
      if(S[mid] > p) right = mid;
      else left = mid;
    }
    if(S[left] == T[i]) c++;
  }
  printf("%d\n",c);

  return 0;
}

