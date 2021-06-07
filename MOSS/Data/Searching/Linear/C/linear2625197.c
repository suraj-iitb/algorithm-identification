#include <stdio.h>

int main(){
  int n,q;
  int S[10000], T[500];
  int count=0;
  int i,j;
  int si;
  scanf("%d", &n );
  //printf("%d\n", n);
  for (i=0 ; i<n; i++ ) {
    scanf("%d", &S[i] );
    //printf("%d ", S[i] );
  }
  //printf("\n");
  scanf("%d", &q );
  for (i=0 ; i<q; i++ ) {
    scanf("%d", &T[i] );
  }

  si=0;
  for(i=0; i<q; i++){
    for(j=si; j<n ; j++){
      //printf("S=%d T=%d",j,i);
      if(S[j]==T[i]){
        count++;
        break;
      }
    }
  }
  printf("%d\n", count );
  return 0;
}
