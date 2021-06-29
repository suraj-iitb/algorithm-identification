#include<stdio.h>
int main(){
  int n,S[100000],q,T[50000],i,  cnt=0;
  int r,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    l=0;
    r=n;
    while(l<r){
      m = (l+r)/2;
      if(T[i]==S[m]){
	cnt++;
	break;
      }
      else if(T[i]<S[m]) r=m;
      else if(T[i]>S[m]) l=m+1;
      else l=m+1;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
	
    

