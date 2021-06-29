#include<stdio.h>
#include<stdlib.h>
 
#define NMAX 10000
#define QMAX 500
 
int main(void){
  int i,j,n,S[NMAX],q,T[QMAX],C=0;
 
  scanf("%d", &n);
  if(n>NMAX) exit(1);
  for(i=0;i<n;i++)scanf("%d", &S[i]);
 
  scanf("%d", &q);
  if(q>QMAX) exit(1);
  for(i=0;i<q;i++)scanf("%d", &T[i]);
 
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
        C++;
        break;
      }
    }
  }
 
  printf("%d\n",C);
  return 0;
}
