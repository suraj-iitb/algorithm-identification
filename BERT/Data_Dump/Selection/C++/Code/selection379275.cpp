#include<iostream>
using namespace std;

int main()
{
  int N,h,count=0;

  cin >> N;

  int A[N];

  for(int i=1;i<=N;i++)
    {
      cin >> A[i];
    }

  int mini;
  for(int i=1;i<=N;i++)
    {
      mini=i;
      for(int j=i;j<=N;j++)
	{
	  if(A[j]<A[mini])
	    {
	      mini=j;
	    }
	}
      if(A[i] != A[mini])count++;
      h = A[i];
      A[i] = A[mini];
      A[mini] = h;  
    }

  for(int i=1;i<=N;i++)
    {
      cout << A[i];
      if(i != N)cout << " ";
    }
  cout  << endl << count << endl;

  return 0;
}
