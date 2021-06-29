#include <iostream>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, i, *A, k;
	cin >> n;
	A = new int(n);
	r(i, n)
		cin >> A[i];

	int  j, v;
	for (i = 1; i < n; i++)
	{
		r(k, n)
		{
			if (k)cout << " ";
			cout << A[k];
		}
		cout << endl;
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}

	r(k, n)
	{
		if (k)cout << " ";
		cout << A[k];
	}
        cout<<endl;
	return 0;
}

