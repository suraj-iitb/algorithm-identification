#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
static const int MAX = 200000;
void show_st(int *st, int N)
{
  for(int i = 0; i < N ; i++)
  {
    if(i > 0)cout << " ";
    cout << st[i];
  }
  cout << endl;
}
void sort_1(int *st, int N)
{
  int j,v;
  for(int i = 1 ; i < N ; i++)
  {
    j = i - 1;
    v = st[i];
    while(j >= 0 && st[j] > v)
    {
      st[j + 1] = st[j];
      j --;
    }
    st[j + 1] = v;
    show_st(st,N);
  }
}
int main()
{
  int n,R[MAX];
  cin >> n;
  for(int i = 0; i < n ; i++ )cin >> R[i];
  show_st(R,n);
  sort_1(R,n);
  return 0;
}

