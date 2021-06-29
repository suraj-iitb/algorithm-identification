#include <stdio.h>

#define N 1000000

int main(){

  int i;
  int j;
  int n;
  int q;
  int count=0;
  int s[N];
  int t[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
