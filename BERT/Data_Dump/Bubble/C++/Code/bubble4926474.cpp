
#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}

	
	bool flag = true;

	int counter = 0;
	while (flag) 
	{
		flag = false;
		
		for (int j = n - 1; j >= 1; j--) 
		{
			int tmp = 0;
			if (a [j] < a[j - 1]) 
			{
				tmp = a[j];
				a[j] = a[j-1];
				a[j - 1] = tmp;
				flag = true;
				counter++;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		if (i == n - 1) {
			cout << a.at(i) << endl;
		}
		else {
			cout << a.at(i) << " ";
		}
	}

	cout << counter << endl;
	
}












