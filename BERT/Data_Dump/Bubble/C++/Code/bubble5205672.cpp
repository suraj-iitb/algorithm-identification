#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n,list[100],count=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  cin>>list[i];
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=n-1;j>i;j--){
      if(list[j]<list[j-1]){
    swap(list[j],list[j-1]);
    count++;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    if(i)cout<<' ';
    cout<<list[i];
  }
  cout<<endl<<count<<endl;
  return 0;
}
