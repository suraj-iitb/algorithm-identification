#include<stdio.h>
#define N 10000
int main(){
  int cnt=0,cnt1=0;
  int i,j,n,q,S[N],T[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	cnt1=1;
	cnt++;
      }
      if(cnt1==1){break;
      }
    }
    cnt1=0;
  }
	  printf("%d\n",cnt);
  return 0;
}

