#include<stdio.h>
int binarySearch();
int S[100000],T[50000],k=0,j,i,q,n;
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++)binarySearch();
  printf("%d\n",k);
  return 0;
}

binarySearch(){
  int r,m,l;
  l = 0;
  r = n;

  while(l < r){
    m = (l + r) / 2;
    if(S[m] == T[i]){
      k++;
      break;
    }
    else if(T[i] < S[m])
      {
	r = m;
      }
    else{
      l = m + 1;
    }
  }
}
