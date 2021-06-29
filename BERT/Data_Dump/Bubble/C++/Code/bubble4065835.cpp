#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int BubbleSort(){
	int cnt = 0;
	int i = 0;
	while(true){
		if(i == n)break;
		for(int j=n-1;j > i;--j){
			if(v[j] < v[j-1]){
				swap(v[j], v[j-1]);
				cnt++;
			}

		}
		i++;
	}
	return cnt;
}

int main(){
	cin >> n;
	int vin;
	for(int i=0; i<n; ++i){
		cin >> vin;
		v.push_back(vin);
	}

	int ans = BubbleSort();
	for(int k=0;k < n;++k){
		cout << v[k];
		if(k != n-1) cout << " ";
	}
	cout <<endl;
	cout << ans << endl;

	return 0;
}
