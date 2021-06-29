#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100

int main()
{
  int A[MAX];
  int i, j,minj,N;
  int count = 0;
  scanf("%d", &N);
      for (i = 0; i<N;i++)
        scanf("%d", &A[i]);
 for(i=0;i<N;i++)
 {
     minj = i;
     for(j = i;j<N;j++)
     {
         if(A[j] < A[minj])
                minj = j;
     }
                if(A[i] != A[minj])
                {
                    swap(A[i], A[minj]);
                    count++;
                }
 }
          for(int a = 0;a<N-1;a++)
              {printf("%d", A[a]);
              printf(" ");}
          printf("%d\n", A[N-1]);
          printf("%d\n", count);
  return 0;
}

