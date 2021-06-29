#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void trace(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}
void insertionsort(int a[], int n) {
	int j, i, v;
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j+1]=v;
		trace(a,n);
	}
}


int main(){
	int n, i, j;
	int a[100];
    cin>>n;
	for (i = 0; i < n; i++) {
	cin>>a[i];
	}
	trace(a, n);
	insertionsort(a, n);
	return 0;
}
