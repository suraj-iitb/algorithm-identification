#include<stdio.h>
#include<stdlib.h>
#define N 10000

int main(){

  int n, q, i, j, k=0, cnt=0, cnt2=0, u[N];
  int s[N], t[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(s[i]==t[j]){
	u[cnt]=s[i];
	cnt++;
	break;
      }
    }
  }
  /*  for(i=0;i<cnt;i++){
    for(j=i+1;j<cnt;j++){
      if(u[i]==u[j])cnt2++;
    }
    }*/

  printf("%d\n",cnt);
  return 0;
}
