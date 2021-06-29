#include <bits/stdc++.h>

using namespace std;

void output(vector<int> a)
{
  for(int i = 0;i < a.size() - 1;i++)
  {
    cout << a[i] << " ";
  }
  cout << a[a.size() - 1] << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i < n;i++)
  {
    cin >> a[i];
  }
  for(int i = 0;i < n;i++)
  {
    sort(a.begin(), a.begin() + i + 1);
    output(a);
  }
  return 0;
}

