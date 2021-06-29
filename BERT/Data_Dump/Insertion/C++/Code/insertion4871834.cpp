#include "iostream"
using namespace std;

	int n;
	int a[20000];
	int j;
	
void print()
{
	for(int i = 0;i < n;i++)
	{
		if(i)
		cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
}


int main()
{
	
	int i;


	int key;

	cin >> n;

	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
	}
	/*
	for(i = 0;i < n;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	*/
	print();
	for(int i = 1;i < n; i++ )
	{
		key = a[i];

		j = i - 1;

		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
			a[j+1] = key;
		}
		/*
		for(int i = 0; i < n; i++)
			cout<<a[i]<<' ';
			cout<<endl;
			*/
		print();
	}
	return 0;
}


