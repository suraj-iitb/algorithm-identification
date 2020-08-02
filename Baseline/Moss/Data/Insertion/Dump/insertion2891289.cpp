#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

long long int INF = 1e18;
using namespace std;

typedef pair<long long int, long long int> P;

int main(){
	
	int N;
	cin >> N;
	
	int A[200];
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	vector<int> v;
	for(int i = 0; i < N - 1; i++){
		v.push_back(A[i]);
		sort(v.begin(), v.end());
		for(int j = 0; j < v.size(); j++){
			cout << v[j] << " ";
		}
		for(int j = v.size(); j < N - 1; j++){
			cout << A[j] << " ";
		}
		cout << A[N - 1] << endl;
	}
	v.push_back(A[N - 1]);
	sort(v.begin(), v.end());
	for(int j = 0; j < v.size() - 1; j++){
		cout << v[j] << " ";
	}
	cout << v[v.size() - 1] << endl;
	
	return 0;
}
