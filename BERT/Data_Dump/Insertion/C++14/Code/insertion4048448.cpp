#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

long long read(void) {
	long long d;
	cin >> d;
	return d;
}
double readReal(void) {
	double d;
	cin >> d;
	return d;
}
string readString(void) {
	string s;
	cin >> s;
	return s;
}
void println(void) {
	cout << endl;
}
template <typename T>void print(T t) {
	cout << t;
}
template <typename T>void println(T t) {
	print(t);
	println();
}
template <typename T>
void print(const vector<T> &v, const string &sep = " ") {
	if (v.empty()) return;
	print(v[0]);
	for(int i = 1;  i < v.size(); ++i) {
		print(sep);
		print(v[i]);
	}
	return;
}
template <typename T>
void println(const vector<T> &v, const string &sep = " ") {
	print(v, sep);
	println();
	return;
}

int InsertSort(vector<int> *v) {
	vector<int> &vec = *v;
	FOR(i, 1, vec.size()) {
		int pivod = vec[i];
		int j = i - 1;
		while(j >= 0 && vec[j] > pivod) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = pivod;
		println(vec);
	}
	return 0;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int size = read();
	vector<int> vec(size);
	REP(i, size) {
		vec[i] = read();
	}
	println(vec);
	InsertSort(&vec);

	return 0;
}

