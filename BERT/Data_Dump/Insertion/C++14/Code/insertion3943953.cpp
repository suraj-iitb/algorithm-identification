#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,x,j,i,k;
  cin>>n;
  vector<int>a(n);
  for(i=0;i<n;i++)
    cin>>a[i];

  for(int i=0;i<n;i++)
    {
    int x=a[i];
    int j=i-1;
    while(j>=0&&a[j]>x)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=x;
    for(k=0;k<n-1;k++)
    cout<<a[k]<<" ";
    cout << a[n-1]<<endl;
  }
 
}


