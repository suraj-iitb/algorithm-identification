#include<iostream>
using namespace std;

int main()
{
	int n, a;
	int b[100];
	cin >> n;
	for (int q = 0; q < n; q++)
		cin >> b[q];
		
	for (int q = 0; q < n - 1; q++)
		cout << b[q] << " ";
	    cout << b[n - 1];
	    cout << endl;

	
		int x;
		for (int q = 1; q < n; q++)
		{
			int z = b[q];
			x = q - 1;
			while (x >= 0 && b[x] > z)
			{
				b[x + 1] = b[x];
					x--;

			}
			b[x+1] = z;
			for (int q = 0; q < n - 1; q++)
				cout << b[q] << " ";
			    cout << b[n - 1];
			    cout << endl;
			

		}

		return 0;
}
