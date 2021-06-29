// Algorithm.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	 
	int a[1004] = {};
	int b; cin >> b;
	for (int i = 0; i < b; i++)		cin >> a[i];

	int v, j;
	for (int i = 1; i < b; i++) {  
		cout << a[0] << flush;
		for (int k = 1; k < b; k++)	cout << ' ' << a[k] << flush;
	    cout << endl;

		v = a[i];  
		j = i - 1;  
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		
	}

	cout << a[0] << flush;
	for (int k = 1; k < b; k++)	cout << ' ' << a[k] << flush;
	cout << endl;
	return 0;


}
