#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N;
	cin >> N;
	int cnt = 0;

	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	bool flag = true;
	while(flag){
		flag = false;
		for(int j=N-1;j>=1;j--){
			if(a[j] < a[j-1]){
				swap(a[j],a[j-1]);
				cnt++;
				flag = 1;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout << a[i];
		if(i!=N-1)cout << " ";
	}
	cout << endl;
	cout << cnt << endl;

	return 0;
}
