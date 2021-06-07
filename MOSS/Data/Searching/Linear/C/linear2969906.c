#include <stdio.h>
#define N_MAX 10000
#define Q_MAX 500
int main(){
  int n;
  int S[N_MAX];
  int q;
  int T[Q_MAX];
  int i,j;
  int key;
  int cont=0;

  //---read---------
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(T[i]==S[j]){
	cont++;
	break;
      }
    }
  }

  printf("%d\n",cont);
  return 0;
}

