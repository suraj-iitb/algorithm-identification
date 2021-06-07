#include <stdio.h>
#define N 100000

int main(void){

  int i,j,n,m,count=0;
  int s[N],t[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&m);

  for(j=0;j<m;j++){
    scanf("%d",&t[j]);
  }

  for(j=0;j<m;j++){
    for(i=0;i<n;i++){
      if(s[i] == t[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
