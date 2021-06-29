#include <iostream>
using namespace std;

int main(void)
{
	int n, an[256];

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> an[i];

	for(int i = 0; i < n; i++)
		cout << an[i] << (i == n - 1 ? "\n" : " ");

	for(int j = 1; j < n; j++){
		int key = an[j];
		int i = j - 1;
		for( ; i >= 0 && an[i] > key; i--) {
			an[i + 1] = an[i];
		}
		an[i + 1] = key;
		for(int i = 0; i < n; i++)
			cout << an[i] << (i == n - 1 ? "\n" : " ");
	}

	return 0;
}
