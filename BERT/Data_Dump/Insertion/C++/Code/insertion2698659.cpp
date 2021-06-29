#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> a){
	for (int i = 0; i != a.size(); i++){
		cout << (i == 0 ? "" : " ") << a[i];
	}
	cout << endl;
	return;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i != n; i++)	cin >> a[i];
	show(a);
	int key, j;
	for (int i = 1; i != n; i++){
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		show(a);
	}
}
