//バブルソート 2015／4／15 h25i18 高木 博康
#include <iostream>
using namespace std;

int cnt = 0;

void BubbleSort(int S[], int N){ 
	bool flag;
	do{
		flag = false;
		for(int i = 0; i < N - 1; i++){
			if(S[i] > S[i + 1]){
				int tmp = S[i];
				S[i] = S[i + 1];
				S[i + 1] = tmp;
				cnt++;
				flag = true;
			}
		}
	}while(flag);
}

int main(){
	int n;
	cin >> n;
	int s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	BubbleSort(s,n);
	for(int i = 0; i < n-1; i++){
		cout << s[i] << ' ';
	}
	cout <<s[n-1]<< endl << cnt << endl;
	return 0;
}
