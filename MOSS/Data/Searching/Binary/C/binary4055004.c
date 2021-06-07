#include<stdio.h>

int main(){
  int i,n,N[1000000],q,cnt=0,j,p,m,l,r;
  //arry input
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&N[i]);
  //-------
  scanf("%d",&q);
  for(i=0;i<q;i++){
    l=0;
    r=n;
    scanf("%d",&p);
    //Binary search
    while(l<r){
      m=(l+r)/2;
      if(N[m]==p){
	cnt++;
	break;
      }
      if(p>N[m]){
	l=m+1;
      }
      if(p<N[m]){
	r=m;
      }
    }    
  }
  printf("%d\n",cnt);
  return 0;
}

