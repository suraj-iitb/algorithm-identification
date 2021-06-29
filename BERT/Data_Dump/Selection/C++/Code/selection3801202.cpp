#include"iostream"
using namespace std;
void Selectionsort(int num[], int n);
int main()
{
	int n;
	cin >> n;
	int*num = new int[n];
	int i;
	for (i = 0; i < n; ++i)
		cin >> num[i];
	Selectionsort(num, n);
	return 0;
}
void Selectionsort(int num[], int n)
{
	int i,j,mini,t,k=0;
	for (i = 0; i < n; ++i)
	{
		mini = i;
		for (j = i; j < n; ++j)
			if (num[j] < num[mini])mini = j;
		if(mini!=i)
		{
			t = num[i];
			num[i] = num[mini];
			num[mini] = t;
			++k;
		}
	}
	cout << num[0];
	for (i = 1; i < n; ++i)
		cout << ' ' << num[i];
	cout << endl << k << endl;
}
