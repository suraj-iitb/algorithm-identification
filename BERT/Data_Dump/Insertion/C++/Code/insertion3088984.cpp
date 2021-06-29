#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100;

int main()
{
  int n,A[MAX];
  cin >> n;
  for(int i=0;i<n;i++) cin >> A[i];

  for(int i=0;i<n;i++)
  {
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  for(int i=1;i<n;i++)
  {
    int v = A[i];
    int j = i-1;
    while(j>=0 && A[j]>v)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=v;
    for(int j=0;j<n;j++)
    {
      if(j>0) printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }
}

