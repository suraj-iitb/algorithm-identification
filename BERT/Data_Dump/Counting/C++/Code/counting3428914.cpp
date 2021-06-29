#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &as, int n, int k)
{
  vector<int> bs = vector<int>(n+1);
  vector<int> cs = vector<int>(k+1, 0);

  for (int i = 1; i <= n; i++)
    cs[as[i]]++;

  for (int i = 1; i <= k; i++)
    cs[i] += cs[i-1];

  for (int i = n; i >= 1; i--) {
    bs[cs[as[i]]] = as[i];
    cs[as[i]]--;
  }

  for (int i = 1; i <= n; i++)
    cout << bs[i] << (i==n?'\n':' ');
}


int main()
{
  int n; cin >> n;
  vector<int> as = vector<int>(n+1);
  int k = 0;
  for (int i = 1; i <= n; i++) {
    cin >> as[i];
    k = max(k, as[i]);
  }
  counting_sort(as, n, k);

  return EXIT_SUCCESS;
}

