#include <stdio.h>
int ls (int);
int n, S[10000];
int main(){
  int q,T[500],i,j,x=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    scanf("%d",&T[i]);

  for(i = 0; i < q; i++){
    if(ls(T[i]) == T[i]) x++;
  }

  printf("%d\n",x);

  return 0;
}

int ls(int key){
  int j;
      for(j = 0; j < n; j++){
	if(key == S[j]) return key;
    }
      return 0;
}

