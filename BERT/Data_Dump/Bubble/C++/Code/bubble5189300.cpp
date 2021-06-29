#include<iostream>
using namespace std;

int main()
{
  int n,temp;
  int noofswap=0;
  cin >> n;
  int a[n];

  for(int i=0;i<n;i++)
    {
      cin >> a[i];
    }

  for(int i=0; i<n ;i++)
    {
      for(int k=n-1; k>=i ;k--)
	{
	  if(a[k] < a[k-1])
	    {
	      temp = a[k];
	      a[k] = a[k-1];
	      a[k-1] = temp;
	      
	      noofswap = noofswap + 1;
	    }
	}
    }

  for(int t=0;t<n;t++)
    {
      cout << a[t];    
      if(t != n-1)
       cout << " ";
    }
  cout << endl;
  cout << noofswap << endl;


  return 0;
}
