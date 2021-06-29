#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

void print(const vector<int> &data) {
	if (data.empty()) return;
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i];
		if (i != data.size() - 1) cout << " ";
		else cout << endl;
	}
}


void insSort(vector<int> &data){
	int n = data.size();
	for (int i = 0; i < n; ++i){
		int tmp = data[i];
		int j = i - 1;
		while ( j >= 0 && (data[j] > tmp)){
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = tmp;
		print(data);
	}
}


int main(){
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	insSort(v);
	return 0;
}
