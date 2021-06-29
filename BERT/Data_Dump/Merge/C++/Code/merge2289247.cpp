

#include <iostream>
#include <vector>

int __counter__ = 0;

namespace std {

	void trace(vector<int> v) {
		for (int i = 0; i < v.size(); ++i) {
			if (i != v.size() - 1)
				cout << v[i] << " ";
			else
				cout << v[i] << endl;
		}
	}

	void merge(vector<int> &v, vector<int> &L, vector<int> &R) {
		vector<int>::iterator i = L.begin();
		vector<int>::iterator j = R.begin();	
		for (vector<int>::iterator x = v.begin(); x != v.end(); ++x){
			if (j == R.end() || i != L.end() && *i <= *j) {
				*x = *i;
				++i;
			}
			else{
				*x = *j;
				++j;
			}
			__counter__++;
		}
	}

	void merge_sort(vector<int> &v) {
		if (v.size() == 1)
			return;
		vector<int> L;
		vector<int> R;
		L.assign(v.begin(), v.begin() + (v.size() / 2));
		R.assign(v.begin() + (v.size() / 2), v.end());
		merge_sort(L);
		merge_sort(R);
		merge(v, L, R);
	}

}//std

int main() {
	{
		using namespace std;
		int n;
		cin >> n;
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		merge_sort(v);
		trace(v);
		cout << __counter__ << std::endl;

	}
}
