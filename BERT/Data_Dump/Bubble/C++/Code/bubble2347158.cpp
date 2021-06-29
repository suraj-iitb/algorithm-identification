#include <iostream>
//#include <conio.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int dem =0;
	int a[100000];
	for (int i =0; i < n; i++)
		cin>>a[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j -1];
				a[j - 1] = temp;
				dem++;
			}
		}        
	}
	cout<<a[0];
	for (int i = 1; i < n; i++)
		cout << " "<< a[i];
	cout<< endl;
	cout<< dem << endl;
	return 0;
}
