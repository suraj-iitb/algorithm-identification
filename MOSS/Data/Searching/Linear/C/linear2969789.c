#include <stdio.h>

void linearSearch(int,int);

int count = 0;
int  S[10000];

int main(){

  int n,q,i,j;
  int T[10000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    linearSearch(T[i],n);
  }
  printf("%d\n",count);
  return 0;
}
void linearSearch(int key,int n){
  int i;
  for(i=0;i<n;i++){
    if(key == S[i]){
      count++;
      break;
    }
  }
}

