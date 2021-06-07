#include <stdio.h>
#include <stdlib.h>

int main(){

  int n,q,c=0;

  scanf("%d",&n);

  int *s = (int *)malloc(sizeof(int)*n);
  if (s == NULL) {
    return 0;
 }


  for(int i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  int *t = (int *)malloc(sizeof(int)*q);
  if (t == NULL) {
     return 0;
 }

  for(int i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(int i=0;i<q;i++){
    for(int j=0;j<n;j++){
      if(t[i]==s[j]){
        c++;
        break;
      }
    }
  }

  printf("%d\n",c);

  free(s);
  free(t);

  return 0;

}

