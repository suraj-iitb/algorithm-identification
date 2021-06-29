#include<iostream>
#define N 100
using namespace std;
int main()
{
	int i;
	int j;
	int q;
	int n;
	int swap;
	int num[N];
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> num[i];
		if(i>0)
			cout << " ";
			cout << num[i];
	}
	cout << endl;
	for (i = 1;i < n;i++)
	{
		j = i;
		while (j > 0 && num[j] < num[j - 1])
		{
			swap = num[j];
			num[j] = num[j-1];
			num[j-1] = swap;
			j--;
		}
		for (q = 0;q < n;q++)
		{
			if (q > 0)
				cout << " ";
				cout << num[q];
		}
		if (i < n)
		{
			cout << endl;
		}
	}
    return 0;
}


