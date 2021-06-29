#include<iostream>
using namespace std;

int main()
{
	int k;
	int a[1000];
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> a[i];
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j<i; j++){
			int h = a[i];
			if (a[i] < a[j]){
				for (int s = i; s > j; s--){
					a[s] = a[s - 1];
				}
				a[j] = h;
				break;
			}
		}
		bool t = false;
		for (int z = 0; z < k; z++){
			if (t)cout << ' ';
			cout << a[z];
			t = true;
		}cout << endl;
	}
	return 0;
}


