#include <iostream>
using namespace std;

int bubsort(int A[],int N)
{
  int x=0;
  bool flag=1;
  for(int i=0;flag;i++)
    {
      flag=0;
      for(int j=N-1;j>=i+1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      swap(A[j],A[j-1]);
	      flag=1;
	      x++;
	    }
	}
    }
  return x;
}

int main ()
{
  int A[100],N,x;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>A[i];

  x=bubsort(A,N);

  for(int i=0;i<N;i++)
    {
      if(i) cout << " ";
      cout << A[i];
    }
  cout << endl;
  cout << x << endl;

  return 0;
}

