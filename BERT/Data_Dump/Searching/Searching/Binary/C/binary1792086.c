#include<stdio.h>

int main()
{

  int n,S[100000],q,T[50000],i,j;
  int count=0;
  int l,r,m;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){
    l=0;
    r=n;

    while(l<r){

      m=(l+r)/2;

      if(S[m]==T[j]){
	count++;
	break;
      }
      else if(S[m]>T[j]){
	r=m;
      }
      else{
	l=m+1;
      }
    }
  }
  printf("%d\n",count);

  return 0;
}
