#include <stdio.h>
#define N 100000
#define Q 500
int linearSearch(int*, int);
int n;
int main()
{
  int q;
  int s[N],t[Q];
  int i;
  int c=0,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t[i]);
  }

  for(i=0; i<q; i++){
    c = linearSearch(s,t[i]);
    if(c!=1) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
  
}

int linearSearch(int *x,int key)
{
  int i;
  for(i=0; i<n; i++){
    if(x[i]==key) return 0;
  }
  
  return 1;
}
