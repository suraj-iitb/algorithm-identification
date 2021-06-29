#include <iostream>
using namespace std;

void show(int A[],int N)
{
	for (int i=0;i<N;i++)
	{
	if (i>0)  cout<<" ";
	    cout<<A[i];
	}
	cout<<endl; 
}

int main (void)
{
	int N;
	cin>>N;
	int *A=new int [N];
	for (int i=0;i<N;i++)
	    cin>>A[i];
	int temp,j;
	for (int i=0;i<N;i++)
	{
		j=i-1;
		temp=A[i];
		while (j>=0&&A[j]>temp)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
		show(A,N);
	}
	delete[]A;
	return 0;
}
