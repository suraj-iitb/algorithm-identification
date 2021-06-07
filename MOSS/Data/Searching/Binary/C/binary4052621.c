#include <stdio.h>

int main(){
  int n,q,k,S[100000],T[50000],left,right,mid,count=0;
  scanf("%d",&n);
  for(k=0;k<n;k++){
    scanf("%d",&S[k]);
  }
  scanf("%d",&q);
  for(k=0;k<q;k++){
    scanf("%d",&T[k]);
  }
  
  for(k=0;k<q;k++)
    {
      left = 0;
      right = n;
      while(left<right)
	{
	  mid=(left+right)/2;
	  if(S[mid]==T[k]){count++;break;}
	  else if(T[k]<S[mid]){right = mid;}
	  else {left = mid+1;}
	}
    }
  printf("%d\n",count);
  return 0;
}

