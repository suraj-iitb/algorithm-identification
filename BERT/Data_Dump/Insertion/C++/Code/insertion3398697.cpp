#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int n;
  scanf("%d", &n);

  vector<int> ar;

  for(int i=0; i<n; i++)
  {
    int temp;
    scanf("%d", &temp);
    ar.push_back(temp);
  }

  int l = 0;
  while(l!=n-1)
  {
    printf("%d ",ar[l]);
    l++;
  }
  printf("%d\n", ar[l]);

  for(int i=1; i<n; i++)
  {
    int medium = ar[i];
    int j = i-1;
    while(j>=0 && ar[j] >= medium)
    {
      ar[j+1] = ar[j];
      j--;
    }
    ar[j+1] = medium;

    int l = 0;
    while(l!=n-1)
    {
      printf("%d ",ar[l]);
      l++;
    }
    printf("%d\n", ar[l]);

  }
  return 0;
}

