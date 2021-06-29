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
  cout << st[N] << endl;//交換回数の表示
}
void sort_2(int *st, int N)
{
  int tmp,cnt = 0;
  for(int i = 0 ; i < (N - 1) ; i++)
  {
    for(int j =(N -1); j > i; j--)
    {
      if(st[j] < st[j - 1])
      {
        tmp = st[j - 1];
        st[j - 1] = st[j];
        st[j] = tmp;
        cnt ++;
      }
    }
  }
  st[N] = cnt;
}
int main()
{
  int n,R[MAX];
  cin >> n;
  for(int i = 0; i < n ; i++ )cin >> R[i];
  sort_2(R,n);
  show_st(R,n);
  return 0;
}
