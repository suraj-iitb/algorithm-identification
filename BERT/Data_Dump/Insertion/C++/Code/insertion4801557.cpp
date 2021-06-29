#include <iostream>
using namespace std;

int main()
{	
	int  m = 0;
	int arr[101];
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	//insertSort
	for (int k = 0; k < m; k++)
	{
		cout << arr[k];
		if (k < m - 1)  cout << " ";
	}
	cout << endl;
	for (int i = 1; i < m; i++) {
		int temp = arr[i];
		int j = i - 1;
		
		while (j >= 0 && temp < arr[j]) {
			arr[j + 1] = arr[j];
				j--;
		}
		arr[j+1] = temp;
		for (int k = 0; k < m; k++)
		{
			cout << arr[k];
			if (k < m - 1)  cout <<" ";
		}

		cout << endl;
	}


}

