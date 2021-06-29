#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector<int> data(n);
  rep(i,n) 
  {
    cin >> data[i];
    if(i > 0) cout << " ";
    cout << data[i];
  }
  cout << endl;
  for(int i = 1; i < n ; i++)
  {
    int v = data[i];
    int j = i - 1;
    while(j >= 0 && data[j] > v)
    {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = v;
    rep(i, n) 
    {
      if(i > 0) cout << " ";
      cout << data[i];
    }
    
    cout << endl;
  }
  return (0);
} 
