#include<stdio.h>
#define Z 2000001
int a[Z],b[Z],c[Z];
main()
 {
  int i,j,k,l=0;
  scanf("%d", &k);
  for(i = 0; i < k; i++)
    {
      scanf("%d", &a[i]);
      c[a[i]] += 1; 
      if(a[i] > l)
        {
      l = a[i];
        }
    } 
  for(i = 1; i <= l; i++)
    {
      c[i] = c[i] + c[i-1];
    }
 
  for(j = k-1;j >= 0; j--)
    {
      b[c[a[j]]] = a[j];
      c[a[j]]--;
    }
 
  for(i = 1; i <= k; i++)
    {
      printf("%d", b[i]);
      if(i == k) printf("\n");
      else printf(" ");
    }
  return 0;
 }
