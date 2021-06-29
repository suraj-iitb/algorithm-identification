#include<iostream>
using namespace std;

int sw=0;
int bubbleSort(int n, int A[])
{
  bool flag=1;
  for(int i=0;flag;i++)
  {
    flag=0;
    for(int j=n-1;j>i;j--)
    {
      if(A[j]<A[j-1])
      {
        swap(A[j],A[j-1]);
        flag=1;
        sw++;
      }
    }
  }
}

int main()
{
  int n;
  int A[100];
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>A[i];
  }
  bubbleSort(n,A);
  for(int i=0;i<n;i++)
  {
    if(i>0) cout<<" ";
    cout << A[i];
  }
  cout<<endl<<sw<<endl;;
  return 0;
}
