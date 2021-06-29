#include <iostream>
using namespace std;
#include <algorithm>

int main(void){

	int n;
	int a[100];
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bool flg = true;
	while (flg){
		flg = false;
		for (int i = n - 1; i > 0; i--){
			if (a[i] < a[i - 1]){
				swap(a[i], a[i - 1]);
				flg = true;
				count++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
	cout << a[n - 1] << endl << count << endl;
}
