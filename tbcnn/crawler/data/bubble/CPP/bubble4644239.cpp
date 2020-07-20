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

  bool flag = true;
  int cnt = 0;
  while (flag)
  {
    flag = false;
    for (int i = N - 1; i >= 1; i--)
    {
      if (A.at(i) < A.at(i - 1))
      {
        swap(A.at(i), A.at(i - 1));
        flag = true;
        cnt++;
      }
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
