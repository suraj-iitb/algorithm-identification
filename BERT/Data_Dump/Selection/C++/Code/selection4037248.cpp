#include<iostream>
using namespace std;

int printout(int n,int A[])
{
  for(int i=0;i<n;i++)
  {
    if(i) cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
}

int selectionSort(int n,int A[])
{
  int sw=0;
  for(int i=0;i<n;i++)
  {
    int minj=i;
    for(int j=i;j<n;j++)
    {
      if(A[j]<A[minj]) minj=j;
    }
    if(minj!=i)
    {
      swap(A[minj],A[i]);
      sw++;
    }
  }
  return sw;
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
  int count;
  count=selectionSort(n,A);
  printout(n,A);
  cout<<count<<endl;
  return 0;
}
