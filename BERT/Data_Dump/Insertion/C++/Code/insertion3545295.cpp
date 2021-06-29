#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100

int main()
{
  int is[MAX];
  int i, j,v,N;
  scanf("%d", &N);
      for (i = 0; i<N;i++)
	    {scanf("%d", &is[i]);}
    for(int a = 0;a<N-1;a++)
              {printf("%d", is[a]);
              printf(" ");}
              printf("%d\n", is[N-1]);
  for(i = 1; i<N; i++)
    {
      v = is[i];
      j = i-1;
      while(j >= 0 &&is[j] > v)
          {is[j+1] = is[j];
          is[j] = v;
          j--;
          }
          for(int a = 0;a<N-1;a++)
              {printf("%d", is[a]);
              printf(" ");}
          printf("%d\n", is[N-1]);
  }
  
  return 0;
} 
