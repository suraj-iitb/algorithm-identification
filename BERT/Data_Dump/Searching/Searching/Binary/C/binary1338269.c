#include<stdio.h>
main(){
  int i,flag,sum,m,n,left,mid,right,S[100000],T[50000];
  scanf("%d",&m);
  for(i=0;i<m;i++)scanf("%d",&S[i]);
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&T[i]);
  
  for(i=0;i<n;i++){
    left = 0;
    right = m;
    flag = 0;
    while(left < right){
      mid = (left + right) / 2;
      if(S[mid] == T[i]){
	flag = 1;
	break;
      }
      else if(T[i] < S[mid])right = mid;
      else left = mid + 1;
    }
    if(flag==1)sum++;
  }
  printf("%d\n",sum);
  return 0;
}
