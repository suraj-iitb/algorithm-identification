#include <iostream>
int A[100];
using namespace std;
int main()
{
	int i,j,k,v,N;
	cin >> N; 
	for(i=0;i<N;i++)
		cin >> A[i];
	for(i=0;i<N;i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0;k<N;k++)
		{
			cout << A[k];
			if(k<N-1)
				cout <<" ";
		}
		cout << endl;
	}
	return 0;
}
