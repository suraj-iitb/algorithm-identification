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
	
	int n;
	cin >> n;
	
	int A[2000];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){
			if(A[j] > A[j + 1]){
				ans++;
				swap(A[j], A[j + 1]);
			}
		}
	}
	
	sort(A, A + n);
	for(int i = 0; i < n - 1; i++){
		cout << A[i] << " ";
	}
	cout << A[n - 1] << endl;
	
	cout << ans << endl;
	
	return 0;
}
