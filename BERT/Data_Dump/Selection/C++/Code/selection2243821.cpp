#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int dataset;
	cin >> dataset;
	int coeunt = 0;
	int a[100];

	for (int i = 0; i < dataset; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < dataset; i++)
	{
		int minj = i;
		for (size_t j = i + 1; j < dataset; j++)
		{
			if (a[minj] > a[j]) { minj = j;  }
		}
		if(i!=minj){
			int d = a[i];
			a[i] = a[minj];
			a[minj] = d;
			coeunt++;
		}
		
		
	}

	for (int i = 0; i < dataset; i++)
	{
		if (i > 0) {
			cout << " " << a[i];
		}
		else {
			cout << a[i];
		}
	}

	cout << endl << coeunt << endl;
}
