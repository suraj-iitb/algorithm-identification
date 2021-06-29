#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream>
#include <numeric>

typedef long long lint;
typedef long double ldouble;
using namespace std;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);++i)
#define all(x) (x).begin(),(x).end()
#define sl(c) (('a')<=(c)&&(c)<=('z'))
#define ll(c) (('A')<=(c)&&(c)<=('Z'))
#define PI 3.141592653589793
#define cout (cout<<fixed<<setprecision(15))
#define makeupper(t) (transform(all(t),t.begin(),::toupper))
#define makelower(t) (transform(all(t),t.begin(),::tolower))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define sum(a) accumulate(all(a),0)
#define NEXT_LINE string junk; getline(cin, junk);
inline lint* arr1(lint x) {
	lint *array = new lint[x];
	rep(i, x)array[i] = 0;
	return array;
}
inline lint** arr2(lint x, lint y) {
	lint **array = new lint*[x];
	rep(i, x)array[i] = new lint[y];
	rep(i, x)rep(j, y)array[i][j] = 0;
	return array;
}
inline vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}
inline ldouble max(vector<ldouble> a) {
	ldouble M = a[0];
	rep(i, a.size())if (M < a[i])M = a[i];
	return M;
}
inline ldouble min(vector<ldouble> a) {
	ldouble m = a[0];
	rep(i, a.size())if (m > a[i])m = a[i];
	return m;
}
inline lint max(vector<lint> a) {
	lint M = a[0];
	rep(i, a.size())if (M < a[i])M = a[i];
	return M;
}
inline lint min(vector<lint> a) {
	lint m = a[0];
	rep(i, a.size())if (m > a[i])m = a[i];
	return m;
}
inline ldouble sum2(vector<ldouble> a, int n) {
	vector<ldouble> b;
	b.resize(a.size());
	rep(i, a.size())b[i] = powl(a[i], n);
	return sum(b);
}
inline lint sum2(vector<lint> a, int n) {
	lint sum=0;
	rep(i, a.size())sum += powl(a[i], n);
	return sum;
}
inline ldouble dist2(vector<ldouble> a, vector<ldouble> b,int num) {
	if (a.size() != b.size())return -1;
	vector<ldouble> c;
	c.resize(a.size());
	rep(i, a.size())c[i] = abs(b[i] - a[i]);
	if (num == 0)return max(c);
	else return pow(sum2(c, num), 1. / num);
}
inline ldouble dist2(vector<lint> a, vector<lint> b, int num) {
	if (a.size() != b.size())return -1;
	vector<lint> c;
	c.resize(a.size());
	rep(i, a.size())c[i] = abs(b[i] - a[i]);
	if (num == 0)return max(c);
	else return pow(sum2(c, num),1./num);
}
/*inline vector<int> cross(vector<int> a, vector<int> b) {
	return { a[1] * b[2] - a[2] * b[1],a[2] * b[0] - a[0] * b[2],a[0] * b[1] - a[1] * b[0] };
}*/
vector<int> insertionSort(vector<int> a);
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	a=insertionSort(a);
}
vector<int> insertionSort(vector<int> a) {
	int n = a.size();
	int v;
	rep(i, n)cout << (i ? " " : "") << a[i];
	cout << "\n";
	repi(i, 1, n) {
		v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		rep(i, n)cout <<(i?" ":"")<< a[i];
		cout << "\n";
	}
	return a;
}
