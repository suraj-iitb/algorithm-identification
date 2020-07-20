#include<iostream>
using namespace std;
void bubbleSort(int a[], int n)
{
	int i, j,k=0,count=0;
	for ( i = n - 1; i>0; i--)
	{
		for (j = n - 1; j > k ; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				count++;
			}
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << " ";
		cout << a[i];
	}
	cout << "\n" << count<<endl;
}
int main()
{
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bubbleSort(a, n);
	return 0;

}
