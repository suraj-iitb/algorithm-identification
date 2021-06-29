#include <iostream>
using namespace std;

int main(){
	int num;
	int a[100];

	cin >> num;
	for ( int i = 0; i < num; i++) cin >> a[i];
	bool flag = true;
	int idx = 0;

	while (flag){
		flag = false;
		for ( int j = num -1; j >0; j--){
			if ( a[j] < a[j-1]){
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				flag = true;
				idx++;
			}
		}
	}
	for ( int i = 0; i < num - 1; i++){
		cout << a[i] << " ";
	}
	cout << a[num - 1] << endl;
	cout << idx << endl;
	return 0;
}
