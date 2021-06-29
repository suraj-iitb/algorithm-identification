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
    for(int j=i-1; j>-1; j--)
    {
      if(medium <= ar[j])
       {
         ar[j+1] = ar[j];
         ar[j] = medium;
       }

      else if(medium > ar[j])
      {
        break;
      }
    }

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

