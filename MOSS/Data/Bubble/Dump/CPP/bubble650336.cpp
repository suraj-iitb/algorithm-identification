#include <iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int A[n];
  int count =0;
  for(int i=0;i<n;i++)
    cin>>A[i];

  for(int i=0;i<n;i++)
    for(int j=n-1;j>i;j--)
      {
	if(A[j]<A[j-1])
	  {
	    swap(A[j],A[j-1]);
	    count++;
	  }
      }
   for(int i=0;i<n;i++)
     {
       cout<<A[i];
       if(i==n-1)
	 cout<<endl;
       else
	 cout<<" ";
     }
   cout<<count<<endl;
}
