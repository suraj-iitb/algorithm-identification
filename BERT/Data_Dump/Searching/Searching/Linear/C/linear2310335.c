#include <stdio.h>
#define NOT_FOUND -1

int linearSearch(int *,int );

int n,q;

int main(){
  int i,x=0,z;
  int s[10000],t[500];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
 
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    z = linearSearch(s,t[i]);
    if(z != NOT_FOUND) x++;
  }

  printf("%d\n",x);
  
  return 0;
}

int linearSearch(int *s,int t)
{
  int i = 0;

    s[n] = t;
    while(s[i] != t){
      i++;
    }
      if(i == n) return NOT_FOUND;
      else return i;
}
