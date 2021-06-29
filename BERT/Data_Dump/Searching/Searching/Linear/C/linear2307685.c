#include <stdio.h>

int main(){
  int S[100000];
  int T[100000];
  int n;
  int q;
  int c=0;
  int i,j,b;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	c++;
	break;
      }
    }
  }



  printf("%d\n",c);

  return 0;
}
