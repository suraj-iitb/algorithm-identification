#include<stdio.h>
#include<stdlib.h>
 
#define NMAX 1000000
#define QMAX 50000
 
int main(void){
  int i,j,n,S[NMAX],q,T[QMAX],C=0;
  int l,r,m,key;
   
  scanf("%d", &n);
  if(n>NMAX) exit(1);
  for(i=0;i<n;i++)scanf("%d", &S[i]);
 
  scanf("%d", &q);
  if(q>QMAX) exit(1);
  for(i=0;i<q;i++)scanf("%d", &T[i]);
 
  for(i=0;i<q;i++){
    l=0; r=n;
    while(l<r){
      m=(l+r)/2;
      if(S[m]==T[i]){
        C++;
        break;
      } else if(T[i]<S[m]){
        r=m;
      } else {
        l=m+1;
      }
    }
  }
     
  printf("%d\n",C);
  return 0;
}
