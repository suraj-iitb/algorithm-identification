#include <iostream>
#include <vector>

#define rep(i,s,N) for(int i=s;i<N;++i) 

template<typename T>
void swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

template<typename T>
void print(std::vector<T> v) {
	for(int i=0;i<v.size();++i){
		if (i==0) std::cout << v[i];
		else std::cout << " " << v[i];
	}
}

template<typename T>
int sort_selection(std::vector<T> &x){
	int counter = 0;
	for (int i=0; i<x.size(); ++i) {
		int min_index = i;
		for (int j=i+1; j<x.size(); ++j) {
			if (x[j] < x[min_index]) min_index = j; 
		}
		if (x[i] == x[min_index]) {
			continue;
		}
		swap(x[i], x[min_index]);
		counter++;
	}
	return counter;
}

using namespace std;

int main() {
	int N;
	cin >> N;
	std::vector<int> x(N);
	for(auto it = x.begin(); it != x.end(); ++it) {
		cin >> *it;
	}
	int swap_count = sort_selection(x);
	print(x); cout << endl;
	cout << swap_count << endl;
	return 0;
}


