#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

template<class T>
void insertion_sort(vector<T>a,int n)
{
  for (int i = 1; i < n; ++i)
  {
    for (int i = 0; i < n; ++i)
    {
      if(i!=n-1) cout<<a[i]<<" ";
      else cout<<a[i]<<endl;
    }
    T v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  for (int i = 0; i < n; ++i)
  {
    if(i!=n-1) cout<<a[i]<<" ";
    else cout<<a[i]<<endl;
  }
}

int main()
{
  int n;
  cin>>n;
  std::vector<int> a(n);
  for(auto&& e: a) 
  {
    cin>>e;
  }
  insertion_sort(a,n);
}
