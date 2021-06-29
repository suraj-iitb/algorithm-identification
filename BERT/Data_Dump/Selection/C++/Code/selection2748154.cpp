#include<bits/stdc++.h>
using namespace std;
void change(int &a, int &b){
	int t = a; a = b; b = t;
}

int main(){

	int n;
	cin >> n;

	int a[101];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++){
		int minj = i;
		for (int j = i; j < n; j++){
			if (a[j] < a[minj]){ minj = j; }
		}
		if (a[i] != a[minj]){ count++; }
		change(a[i], a[minj]);
	}

	for (int i = 0; i < n; i++){
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	cout << count << endl;

	return 0;
}
