#include <stdio.h>
int Search(int);

int S[10000];
int n;

int main(){
  int T[500],q,C=0;
  int i;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }
  for(i = 0; i < q; i++){
    if(Search(T[i])) C++;
  }
  printf("%d\n",C);
  return 0;
}

int Search(int key){
  int i;
  for(i = 0; i < n; i++){
    if(S[i] == key) return 1;
  }
  return 0;
}
