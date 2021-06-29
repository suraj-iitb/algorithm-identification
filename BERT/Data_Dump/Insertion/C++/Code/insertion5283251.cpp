#include<iostream> 
using namespace std;
int main()
{
	int j,key,n,*A;
	cin >> n;
	A = new int [n];
	for(int i=0;i<n;i++)cin >> A[i];
			//print A[]
		cout << A[0];
		for(int a=1;a<n;a++)
		{
			cout << " " << A[a];
		}
		cout << endl;
	for(int i = 1;i<n;i++)
	{
		key = A[i];
		j=i-1;
		while(j>=0&&A[j]>key)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1]=key;
		//print A[]
		cout << A[0];
		for(int a=1;a<n;a++)
		{
			cout << " " << A[a];
		}
		cout << endl;
	}
	delete [] A;
	return 0;
}
