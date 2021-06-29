#include"iostream"
using namespace std;
void Bubblesort(int num[], int n);
int main()
{
	int n;
	cin >> n;
	int*num = new int[n];
	int i;
	for (i = 0; i < n; ++i)
		cin >> num[i];
	Bubblesort(num, n);
	return 0;
}
void Bubblesort(int num[], int n)
{
	int i, j;
	int t,k=0;
	for(i=0;i<n;++i)
		for(j=n-1;j>i;--j)
			if(num[j]<num[j-1])
			{
				t = num[j];
				num[j] = num[j - 1];
				num[j - 1] = t;
				k++;
			}
	cout << num[0];
	for (i = 1; i < n; ++i)
		cout << ' ' << num[i];
	cout << endl << k << endl;
}
