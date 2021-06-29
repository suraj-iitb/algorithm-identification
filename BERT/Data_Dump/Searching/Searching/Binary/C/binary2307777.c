#include <stdio.h>

int main(){
  int S[1000000];
  int T[1000000];
  int n;
  int q;
  int c=0;
  int m;
  int r;
  int l;
  int i,j;

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
      if(T[i]==S[m]){
	c++;
	break;
      }
      if(T[i]>S[m]){
	l=m+1;
      }
      else if(T[i]<S[m]){
	r=m;
      }
    }
  }

  printf("%d\n",c);

  return 0;
}
