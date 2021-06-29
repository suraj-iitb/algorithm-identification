#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define rep(a,t) for(int a=0;a<t;a++) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())
#define pb push_back
int howmanytimes=0;
vector<int> selectionSort(vector<int> A,int N) {
	
	rep(i, N) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		if (A[i] != A[minj]) { howmanytimes++; }
		int swap = A[minj];
		A[minj] = A[i];
		A[i] = swap;

	}
	return A;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>a;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		a.pb(u);
	}
	a = selectionSort(a,n);
	for (int i = 0; i < a.size();i++)
	{
		if (i != 0) { cout << " "; }
		cout << a[i];
	}
	
	cout << endl<<howmanytimes << endl;
	return 0;
}
