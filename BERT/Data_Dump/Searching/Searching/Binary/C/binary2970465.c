#include<stdio.h>
int main(){
  int n,q,i,c=0;
  int l=0,r=0,m=0;
  int key,v;
  scanf("%d",&n);
  
  int S[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }    l=0;
    r=n;

  for(i=0;i<q;i++){
    l=0;
    r=n;
    while(l<r){
      	m=(l+r)/2;
      if(S[m]>T[i]){
	r=m;
      }else if(S[m]<T[i]){
	l=m+1;
      }else if(S[m]==T[i]){
	break;
      }
    }
    if(S[m]==T[i])c++;
  }
  printf("%d\n",c);
  
  return 0;
}
    
      

  

