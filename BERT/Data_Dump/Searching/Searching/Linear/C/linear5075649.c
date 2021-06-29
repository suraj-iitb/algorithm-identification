#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
  int *s, *t;
  s = (int *)malloc(n * sizeof(int));
  t = (int *)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }
  int q;
  scanf("%d",&q);
  for(int i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }
  int ans = 0;
  for(int i = 0; i < q; i++){
    for(int j = 0; j < n; j++){
      if(s[j] == t[i]){
	ans++;
	break;
      }
    }
  }
  free(t);
  free(s);
  printf("%d\n",ans);
}

