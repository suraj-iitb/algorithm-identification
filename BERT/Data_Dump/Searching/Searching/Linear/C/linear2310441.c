#include <stdio.h>

#define N 10000

int Search(int [],int, int);

int main()
{

  int i, S[N], n, q, count = 0, T;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d",&q);
  
  for(i = 0; i < q; i++) {
    scanf("%d",&T);
      if( Search(S, n, T) ) count++;
	 }
  
    printf("%d\n", count);

    return 0;
}


int Search(int S[], int n, int key)
{
  int i = 0;
  S[n] = key;
  while(S[i] != key){
    i++;
  }
  return i != n;
}
