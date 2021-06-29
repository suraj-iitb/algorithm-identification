#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void bubS(vector<int> &data){
	int count = 0;
	for (int i = 0; i < data.size(); ++i){
		for (int j = data.size() - 1; j > i; --j){
			if (data[j] < data[j-1]){
				swap(data[j], data[j - 1]);
				count++;
			}
		}
	}
	for (int i = 0; i < data.size(); ++i){
		cout << data[i];
		if (i == data.size() - 1) cout << endl;
		else cout << " ";
	}
	cout << count << endl;
}


int main(){
	int n; cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) cin >> data[i];

	bubS(data);
}
