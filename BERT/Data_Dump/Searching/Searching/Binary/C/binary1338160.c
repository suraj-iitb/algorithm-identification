#include<stdio.h>
main()
{
  int i,j,n,q,cnt=0;
  int left,right,mid;
  int S[100000],T[50000];
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j = 0; j < q; j++) {
    scanf("%d",&T[j]);
    left = 0;
    right = n;
    while(left < right) {
      mid = (left + right)/2;
      if(T[j] == S[mid]) {
	cnt++;
	break;
      }
      if(T[j] > S[mid]) {
	left = mid + 1;
      }
      else if(T[j] < S[mid]) {
	right = mid;
      }
    }
  }
    printf("%d\n",cnt);
    return 0;
}
