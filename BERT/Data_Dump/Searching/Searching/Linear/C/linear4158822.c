#include <stdio.h>
#define N 10000
#define Q 500

int linearSearch(void);

int S[N], T[Q], n, q;

int main()
{
  int C=0, i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  C=linearSearch();
  printf("%d\n",C);
  
  return 0;
}
  

int linearSearch()
{
  int i, j, C=0;

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
      C++;
      break;
      }
    }
  }
  return C;
}
    

  

