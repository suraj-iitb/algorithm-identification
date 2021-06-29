#include <stdio.h>
 
int main(){
  int n,q;
  int S[10000], T[500];
  int cnt=0;
  int i,j;
  int si;
  scanf("%d", &n );
  
  for (i=0 ; i<n; i++ ) {
    scanf("%d", &S[i] );
    
  }
  
  scanf("%d", &q );
  for (i=0 ; i<q; i++ ) {
    scanf("%d", &T[i] );
  }
 
  si=0;
  for(i=0; i<q; i++){
    for(j=si; j<n ; j++){
      
      if(S[j]==T[i]){
        cnt++;
        break;
      }
    }
  }
  printf("%d\n", cnt );
  return 0;
}
