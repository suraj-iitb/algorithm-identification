#include <stdio.h>

int main(){
  int n,q,i;
  int cnt = 0;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;++i)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;++i)
    scanf("%d",&T[i]);
  
  for(i=0;i<q;++i){
    int left = 0;
    int right = n;
    while(left<right){
      int center = (left+right)/2;
      if(S[center]==T[i]){
	cnt++;
	break;
      }
      else if(S[center]>T[i]){
	right = center;
      }
      else{
	left = center+1;
      }
    } 
  }
  printf("%d\n",cnt);
  
  return 0;
}

