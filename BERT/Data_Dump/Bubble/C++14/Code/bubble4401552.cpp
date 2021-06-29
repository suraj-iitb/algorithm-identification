#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

template<class T>
void bubblesort(vector<T> &a,int& cnt)
{
  int n=a.size();
  bool flag=true;
  while(flag)
  {
    flag=false;
    for (int i = n-1; i >= 1; --i)
    {
      if(a[i]<a[i-1])
      {
        swap(a[i],a[i-1]);
        flag=true;
        cnt++;
      }
    }
  }
}

int main()
{
  int n,cnt=0;
  cin>>n;
  vector<int> a(n);
  for(auto&& e: a) 
  {
    cin>>e;
  }
  bubblesort(a,cnt);
  for (int i = 0; i < a.size(); ++i)
  {
    if(i!=n-1) cout<<a[i]<<" ";
    else cout<<a[i]<<endl;
  }
  cout<<cnt<<endl;
}
