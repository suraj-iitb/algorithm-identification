
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

	int i;
	int tmp = a.at(0);

	int counter = 0;
	int minj;
	int minpt;
	for (i = 0; i < n; i++)
	{
		minj = a.at(i);
		minpt = a.at(i);
		for (int j = i; j < n; j++)
		{
			if (a.at(j) < minj)
			{
				minj = a.at(j);
				minpt = j;
			}
		}

		if (a.at(i) > minj)
		{
		tmp = a.at(i);
		a.at(i) = a.at(minpt);
		a.at(minpt) = tmp;
		counter++;
		}
	
	}

	for (int i = 0; i < n; i++) {
		
		if (i == n - 1) {
			cout << a.at(i) << endl;
		}
		else {
			cout << a.at(i) << " ";
		}
	}

	cout << counter << endl;
	
}












