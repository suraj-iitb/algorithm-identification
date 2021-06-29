#include<bits/stdc++.h>

using namespace std;

int insertionSort(int ,int);
void trace(int , int);

void trace(int A[],int N)
{
  for(int i=0;i<N;i++)
    {
      if(i>0) cout<<" ";
      cout<<A[i];
    }
  cout<<endl;
}

int insertionSort(int A[],int N)
{
  int j,v;
  for(int i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      trace(A,N);
    }
}
  
int main()
{
  int N,A[1000];
  cin>>N;
  for( int i;i<N;i++) cin>>A[i];
  trace(A,N);
  insertionSort(A,N);
}
  
  

