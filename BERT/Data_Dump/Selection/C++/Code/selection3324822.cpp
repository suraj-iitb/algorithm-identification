#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
int a[100];
int main()
{
	int num,sum=0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < num - 1; i++) {
		int minNumber = i;
		for (int k = i + 1; k < num; k++) {
			if (a[k] < a[minNumber]) {
				minNumber = k;
			}
		}
		if (minNumber != i) {
			int temp = a[minNumber];
			a[minNumber] = a[i];
			a[i] = temp;
			sum++;
		}
	}
	cout << a[0];
	for (int i = 1; i < num; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	cout << sum << endl;
	
}
