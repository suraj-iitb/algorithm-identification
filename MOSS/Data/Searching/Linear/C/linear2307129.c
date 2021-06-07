#include <stdio.h>

int  search(int,int *,int);
int main(){
  int n,q;
  int s[100001],t[50000];

  scanf("%d",&n);
  int i;
  for (i=0;i<n;i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  int count = 0;
  for(i=0;i<q;i++)
    if(search(n,s,t[i])) count++;
  printf("%d\n",count);
  return 0;
}

int search(int n,int *s,int t){
  s[n] = t;
  int i=0;
  while(s[i]!=t)i++;
  return i!=n;
}
	       
