#include <iostream>
#include <vector>

#define rep(i,s) for(int i=0; i<s; ++i)

template<typename U>
int sort_bubble(std::vector<U> &x) {
	int swap_count = 0;
	for (int i=0; i<x.size(); ++i) {
		for (int j=x.size()-1; j>i; --j) {
			if (x[j] < x[j-1]) {
				swap_count++;
				U temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}
		}
	}
	return swap_count;
}

template<typename T>
void print(std::vector<T> v) {
	for(int i=0;i<v.size();++i){
		if (i==0) std::cout << v[i];
		else std::cout << " " << v[i];
	}
}

using namespace std;

// input
// N
// x[0] x[1] ...
//
int main(){
	int N;
	cin >> N;
	vector<int> x(N);
	rep(i,N) {
		cin >> x[i];
	}
	// print(x); cout << endl;
	int swap_count = sort_bubble(x);
	print(x); cout << endl;
	cout << swap_count << endl;
	return 0;
}


