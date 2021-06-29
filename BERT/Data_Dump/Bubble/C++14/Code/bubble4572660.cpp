#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;


int main(void)
{
  int n;
  cin >> n;
  vector<int> data(n);
  rep(i,n) cin >> data[i];
  bool flag =  true;
  int cnt = 0;
  while(flag)
  {
    flag = false;
    for(int j = n-1; j > 0; j--)
    {
      if(data[j] < data[j-1])
      {
        swap(data[j],data[j-1]);
        cnt++;
        flag = true;
      }
    }
  }
  //cout << data[0];
  rep(i, n) 
  {
    if(i > 0) cout << " ";
    cout << data[i];
  }
  cout << endl;
  cout << cnt << endl;
  return (0);
} 
