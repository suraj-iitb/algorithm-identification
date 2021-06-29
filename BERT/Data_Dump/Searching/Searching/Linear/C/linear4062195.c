#include<stdio.h>

#define N 10000
#define Q 500

int main(){
  int n,q;
  int s[N],t[Q];
  int i,j,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&t[i]);

  for(i=0;i<q;i++){/*t*/
    for(j=0;j<n;j++){/*s*/
      if(t[i]==s[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
