/* Search I */
#include<stdio.h>
int main(){
  int n,q; /* n: S, q: T */
  int S[10001],T[501]; /* n<=10000, q<=500 */
  int i,j,counter=0;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &T[i]);
  }
  
  /* Linear Search */
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	counter++;
	break;
      }
    }
  }
  
  printf("%d\n",counter);
  return 0;
}
