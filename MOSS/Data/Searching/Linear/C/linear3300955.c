#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define Q 500

int main(){
  int s[N],t[Q],a[N],i,n,q,j,count=0,b,judge;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);
  
  for(i=0;i<n;i++){
    t[q]=s[i];
    j=0;
    judge=0;
    while(t[j]!=s[i]) j++;
    for(b=0;b<count;b++){
      if(t[j]==a[b]){
	judge=1;
	break;
      }
    }
    if(j==q) continue;
    else if(judge==0){
      a[count]=t[j];
      count++;
    }
  } 

  printf("%d\n",count);

  return 0;
}

