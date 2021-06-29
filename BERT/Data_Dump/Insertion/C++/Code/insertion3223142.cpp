#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <math.h>
#include <string.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
//#define int ll
#define INF (1LL<<60)
#define mod 1000000007


int N;
int a[100];

signed main(){

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];


	// 挿入ソート
	for (int i = 1; i < N; i++){
		// print
		for (int n = 0; n < N; n++){
			cout << a[n];
			if (n < N - 1)
				cout << " ";
			else
				cout << endl;
		}

		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

	}


	// print
	for (int n = 0; n < N; n++){
		cout << a[n];
		if (n < N - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}

