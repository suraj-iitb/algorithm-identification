#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100

int main()
{
  int is[MAX];
  int i, j,v,N;
  int count = 0;
  scanf("%d", &N);
      for (i = 0; i<N;i++)
	    scanf("%d", &is[i]);
        int a = 0;
  for(i = N-1;i>=a;a++)
  {
      int v;
      j = i-1;
      while(j>=a)
      {
          if (is[j]>is[j+1])
              {
                  v = is[j +1];
                  is[j+1] = is[j];
                  is[j] = v;
                  count++;
              }
          j--;
      }
  }
          for(int a = 0;a<N-1;a++)
              {printf("%d", is[a]);
              printf(" ");}
          printf("%d\n", is[N-1]);
          printf("%d\n", count);
  return 0;
} 
