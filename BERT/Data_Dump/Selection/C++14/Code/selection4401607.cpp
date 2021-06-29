#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

void selectionsort(vector<int> &a,int& cnt)
{
  int n=a.size();
  for (int i = 0; i < n; ++i)
  {
    int minj=i;
    for (int j = i; j < n; ++j)
    {
      if(a[j]<a[minj]) minj=j;
    }
    if(a[i]!=a[minj]) cnt++;
    swap(a[i],a[minj]);
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
  selectionsort(a,cnt);
  for (int i = 0; i < a.size(); ++i)
  {
    if(i!=n-1) cout<<a[i]<<" ";
    else cout<<a[i]<<endl;
  }
  cout<<cnt<<endl;
}
