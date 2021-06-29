#include <bits/stdc++.h>
using namespace std;

void print(vector<int> A)
{
  for (int i = 0; i < A.size(); i++)
  {
    if (i)
    {
      cout << " ";
    }
    cout << A.at(i);
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  print(A);
  for (int i = 1; i < N; i++)
  {
    int v = A.at(i);
    int j = i - 1;
    while (j >= 0 && A.at(j) > v)
    {
      A.at(j + 1) = A.at(j);
      j--;
    }
    A.at(j + 1) = v;
    print(A);
  }
}
