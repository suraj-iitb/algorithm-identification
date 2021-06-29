#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
  int number;
  cin>>number;
  int list_a[number];
  int m,v;
  for(int i=0;i<number;i++)
  {
    cin>>list_a[i];
  }
  for(int i=1;i<number;i++)
  {
  for(int k=0;k<number;k++)
  {
    if(k>0)cout<<" ";
    cout<<list_a[k];
  }
  cout<<endl;
    for(int j=i-1;j>=0;j--)
    {
      if(list_a[j+1]<=list_a[j])
      {
        m=list_a[j];
        list_a[j]=list_a[j+1];
        list_a[j+1]=m;
      }
    }
  }
  for(int k=0;k<number;k++)
  {
    if(k>0)cout<<" ";
    cout<<list_a[k];
  }
  cout<<endl;
  return 0;
}
