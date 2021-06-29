#include <stdio.h>

#define N 100000

int main()
{
  int n,q,i,j,k,S[N],T[N],m,right,left;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&S[i]);
   
  scanf("%d",&q);

  for(j=0;j<q;j++) scanf("%d",&T[j]);

  for(j=0;j<q;j++){
    left = 0;
      right = n;
      m = n/2;
    while(left<right){
      m = (left+right)/2;
      if(T[j] < S[m])
	right = m;
      else if(T[j] > S[m])
	left = m+1;
      else {
	k++;
	break;
      }
    }
  }

  printf("%d\n",k);

  return 0;
}
  

      

