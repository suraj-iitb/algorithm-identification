#include<stdio.h>

int LinearSearch(int *,int *,int,int);

int main(){
  int n,q;
  scanf("%d",&n);
  int i,S[n];
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  printf("%d\n",LinearSearch(&S[0],&T[0],n,q));
  return 0;
}

int LinearSearch(int *x ,int *y,int n,int q){
  int i,j,cnt=0;
  if(n<q){
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
      if(x[i]==y[j]){
	cnt++;
	break;
      }
    }
  }
  }
  else {
    for(i=0;i<q;i++){
      for(j=0;j<n;j++){
	if(y[i]==x[j]){
	  cnt++;
	  break;
      }
    }
  }
  }
  return cnt;
}

