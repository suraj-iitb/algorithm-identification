#include<iostream>
using namespace std;
void trace(int n, int *A)
{
	cout << A[0];
	for(int i = 1; i<n;i++)
		cout<<" "<<A[i];
	cout << endl;
}

void ist(int n, int *A)
{
	int i,j,v;
	for(i = 1; i<n;i++)
	{
		v = A[i];
		j = i-1;
		while(j>=0 && A[j] > v)
			{
				A[j+1] = A[j];
				j--;
			}
		A[j+1] = v;
		trace(n,A);	
	}
}

int main()
{
	int array[200];
	int n;
	cin >> n;
	for(int i =0; i<n;i++)
		cin>>array[i];
	trace(n,array);
	ist(n,array);
	
	return 0;
	
	
}
