#include<iostream>
#include<climits>
#include<algorithm>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, i, j, *a, coun=0, mini;
	cin >> n;
	a = new int(n);
	bool flag=false;
	r(i, n)cin >> a[i];

	r(i, n-1)
	{	flag=false;
		mini = i;
		for(j=i;j<n;j++)
			if (a[j] < a[mini])
			{
					mini = j;
					flag=true;
			}
		if(flag)
		{			
		swap(a[mini],a[i]);
		coun++;
		}
	}
	
	r(i, n)
	{
		if (i)cout << " ";
		cout << a[i];
	}

	cout << endl << coun << endl;
	return 0;
}
