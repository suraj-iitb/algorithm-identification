#include <stdio.h>

#define NMAX 10000
#define QMAX 500

int LinearSearch (int *, int , int);

int main (void)
{
  int i,n,q,count = 0,result,arrayS[NMAX],arrayT[QMAX];

  scanf ("%d",&n);
  for (i = 0 ; i < n ; i++){
    scanf ("%d",&arrayS[i]);
  }
  scanf ("%d",&q);
  for (i = 0 ; i < q ; i++){
    scanf ("%d",&arrayT[i]);
  }
  
  for (i = 0 ; i < q ; i++){
    result = LinearSearch(arrayS,arrayT[i],n);
    if (result < n)
      count++;
  }

  printf ("%d\n",count);
  return 0;
}

int LinearSearch (int *S, int key, int n)
{
  int i;
  i = 0;

  S[n] = key;
  while (S[i] != key)
    i++;
  if (i == n)
    return n;
  return i;
}
