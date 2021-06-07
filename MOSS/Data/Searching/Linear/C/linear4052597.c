#include<stdio.h>

#define N 10000
#define Q 500

int main()
{
  int n,q,s[N],t[Q],i=0,j,cnt=0;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)
    scanf("%d",&t[i]);

  for(i=0;i<q;i++){ 
      for(j=0;j<n;j++){
	  if(s[j]==t[i]){
	    cnt++;
	    break;
	    }
	}
    }

  printf("%d\n",cnt);

  return 0;
}
