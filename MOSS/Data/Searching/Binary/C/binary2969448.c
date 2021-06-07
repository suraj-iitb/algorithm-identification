#include<stdio.h>

int main(){

  int n,q,i,j,k,C=0,m,r,l;
  int S[100000];
  int T[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }


    for(i=0;i<q;i++){
      r=n;
      l=0;
      while(l<r){
	m=(r+l)/2;
	if(S[m]>T[i]){ 
	  r=m;
	  continue;
	}
	  else if(S[m]<T[i]){
	    l=m+1;
	    continue;
	  }
	  else {
	  C++;
	  break;
	}
	
    }
    }
  printf("%d\n",C);
  return 0;
}

