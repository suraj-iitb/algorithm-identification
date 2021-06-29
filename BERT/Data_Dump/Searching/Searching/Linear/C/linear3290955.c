#include<stdio.h>

int linearSearch(int *,int *,int,int);

int main(){
  int s[10000];
  int t[500];
  int n,q,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);
  printf("%d\n",linearSearch(s,t,n,q));
  return 0;
}
int linearSearch(int *s,int *t,int n,int q){
  int i,j,kazu=0;

  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(t[j]==s[i]){
	kazu++;
	break;
      }
    }
  }
  return kazu;
}

