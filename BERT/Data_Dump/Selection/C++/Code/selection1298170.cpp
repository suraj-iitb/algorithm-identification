#include <iostream>
using namespace std;

int cnt = 0;

void SelectionSort(int S[], int N){
	for(int i = 0; i < N; i++){
		int minj = i;
		for(int j = i; j < N; j++){
			if( S[j] < S[minj]){
				minj = j;
			}
		}
		if(i != minj){
			int tmp = S[i];
			S[i] = S[minj];
			S[minj] = tmp;
			cnt++;
		}
	}
}

int main(){
	int n;
	cin >> n;
	int s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	SelectionSort(s,n);
	for(int i = 0; i < n-1; i++){
		cout << s[i] << ' ';
	}
	cout <<s[n-1]<< endl << cnt << endl;
	return 0;
}
