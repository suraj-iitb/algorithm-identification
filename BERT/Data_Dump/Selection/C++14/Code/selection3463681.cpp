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
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define repir(i,a,b) for(lint i=lint(a);i>lint(b);i--)
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
#define output(v) do{rep(i,v.size())cout<<(i?" ":"")<<v[i];cout<<"\n";}while(0)
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
inline vector<int> cross(vector<int> a, vector<int> b) {
	return { a[1] * b[2] - a[2] * b[1],a[2] * b[0] - a[0] * b[2],a[0] * b[1] - a[1] * b[0] };
}
inline int GCD(int a, int b) {
	if (a < b)swap(a, b);
	if (a%b != 0)GCD(b, a%b);
	else return b;
}
inline vector<lint> primeList(lint n) {
	vector<bool> p(n+1);
	vector<lint> list;
	repi(i,1, n+1)p[i] = true;
	repi(i,2,sqrt(n)+1) {
		if (p[i]) {
			repi(j,2,n/i+1) {
				p[i*j] = false;
			}
		}
	}
	repi(i, 2, n+1)if (p[i])list.push_back(i);
	return list;
}
inline bool isPrime(int num){
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2){
		if (num % i == 0)return false;
	}
	return true;
}
inline lint search(vector<lint> v,lint n) {
	lint left=0,right = v.size()-1;
	while (right >= left) {
		lint mid = (left + right) / 2;
		if (v[mid] == n)return mid;
		else if (v[mid] > n)right = mid - 1;
		else if (v[mid] < n)left = mid + 1;
	}
	return -1;
}
vector<lint> selectionSort(vector<lint>a, lint n) {
	int minj,count=0;
	rep(i, n) {
		minj = i;
		repi(j, i, n) {
			if (a[j] < a[minj])minj = j;
		}
		swap(a[i], a[minj]);
		if(i!=minj)count++;
	}
	output(a);
	cout << count << "\n";
	return a;
}
int main() {
	lint n;
	cin >> n;
	vector<lint> a(n);
	rep(i, n)cin >> a[i];
	selectionSort(a, n);
	a.begin();
}
