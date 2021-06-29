#include <iostream>

using namespace std;

int main(){
	int n, num[200];
	int box, times;
	
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> num[i];
	}

	box = 0;
	times = 0;

	for (int j = 0; j < n - 1; j++){
		for (int i = n - 1; i > 0; i--){
			if (num[i] < num[i - 1]){
				box = num[i];
				num[i] = num[i - 1];
				num[i - 1] = box;
				
				times++;
			}
		}
	}

	cout << num[0];
	for (int j = 1; j < n; j++){
		cout << " " << num[j];
	}

	cout << "\n" << times << endl;

}
