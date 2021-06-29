#include<stdio.h>
#include<stdlib.h>
int main(void){
  int n;
  scanf("%d",&n);
  int i,S[n];
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  int q;
  scanf("%d",&q);
  int j,T[q];
  for(j=0; j<q; j++){
    scanf("%d",&T[j]);
  }
  int same[n];
  int cnt=0;
  int sum=0;
  for(j=0; j<q; j++){
    cnt=0;
    for(i=0; i<n; i++){
	if(S[i]>T[j]){
	  break;
	}else{
	  if(S[i]==T[j]){
	    cnt=1;
	    break;
	  }
	}
    }
    sum+=cnt;
  }
  printf("%d\n",sum);
  return 0;
}

