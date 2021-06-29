#include"iostream"
using namespace std;
void insertionsort(int num[], int n);
int main()
{
	int n;
	cin >> n;
	int*num = new int[n];
	int i;
	for (i = 0; i < n; ++i)
		cin >> num[i];
	insertionsort(num, n);
	return 0;
}
void insertionsort(int num[], int n)
{
	int i, j;
	int key;
	cout << num[0];
	for (j = 1; j < n; ++j)cout << ' ' << num[j];
	cout << endl;
	for(i=1;i<n;++i)
	{
		key = num[i];
		j = i - 1;
		while (j >= 0 && num[j] > key)
		{
			num[j + 1] = num[j];
			--j;
		}
		num[j + 1] = key;
		cout << num[0];
		for (j = 1; j < n; ++j)cout << ' ' << num[j];
		cout << endl;
	}
}
