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

int SelectionSort(){
    if(n == 1) return 0;
	int cnt = 0, minv;
	int num;
	for(int i=0;i < n;++i){
		minv = 100;
		for(int j=i+1;j < n;++j){
			if(v[j] < minv){
				num = j;
				minv = v[j];
			}
		}
		if(v[i] > v[num]){
			swap(v[i], v[num]);
			cnt++;
		}
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

	int ans = SelectionSort();
	for(int k=0;k < n;++k){
		cout << v[k];
		if(k != n-1) cout << " ";
	}
	cout <<endl;
	cout << ans << endl;

	return 0;
}
