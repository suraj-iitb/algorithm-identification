#include<stdio.h>
  int a[100],S[100][10000],T[50000];
int main(void){
  int i,j=0;
  int n,q,count=0;
  int t, x;
  int y=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
 	scanf("%d",&x);
	t=x%100;
	S[t][a[t]]=x;
	a[t]++;
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    t=T[i]%100;
    for(j=0;j<a[t];j++){
      if(T[i]==S[t][j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
