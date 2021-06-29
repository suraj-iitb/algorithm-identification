#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    int minj = i;
    for (int j = i; j < N; j++)
    {
      if (A.at(j) < A.at(minj))
      {
        minj = j;
      }
    }
    if (i != minj)
    {
      cnt++;
      swap(A.at(i), A.at(minj));
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (i)
    {
      cout << " ";
    }
    cout << A.at(i);
  }
  cout << endl;

  cout << cnt << endl;
}
