#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;


int main(void)
{
  int n;
  cin >> n;
  vector<int> data(n);
  rep(i,n) cin >> data[i];
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    int minv = i;
    for(int j = i; j < n; j++)
    {
      if(data[j] < data[minv])
      {
        minv = j;
      }
    }
    swap(data[i],data[minv]);
    if(i != minv) cnt++;
  }
  rep(i,n)
  {
    if(i > 0)cout << " ";
    cout << data[i];
  }
  cout << endl;
  cout << cnt << endl;
  return (0);
} 
