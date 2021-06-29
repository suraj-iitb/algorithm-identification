#include <iostream>
//#include <conio.h>
using namespace std;
//selection sort
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
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}        
		if (min != i)
			{
				int temp = a[min];
				a[min] = a[i];
				a[i] = temp;
				dem++;
			}
	}
	cout<<a[0];
	for (int i = 1; i < n; i++)
		cout << " "<< a[i];
	cout<< endl;
	cout<< dem << endl;
	/*getch();*/
	return 0;
}
