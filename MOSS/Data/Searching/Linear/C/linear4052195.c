#include <stdio.h>
#define N 10000
#define Q 500

int main(){
  int i,j,n,q,con = 0;
  int s[N],t[Q];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
    for(j = 0;j < n;j++){
      if(t[i] == s[j]){
	con++;
	break;
      }
    }
  }
  printf("%d\n",con);
}

