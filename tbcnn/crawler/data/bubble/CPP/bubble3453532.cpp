#include<iostream>
#include<climits>
#include<algorithm>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, i, j, *a, coun=0;
	cin >> n;
	a = new int(n);
	r(i, n)cin >> a[i];


	r(i, n-1)
	{
		j = i + 1;
		r(j, n-1)
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				coun++;
			}
	}
	r(i, n)
	{
		if (i)cout << " ";
		cout << a[i];
	}
	
	cout << endl <<  coun << endl;
	return 0;
}
