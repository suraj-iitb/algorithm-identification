#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <cstring>
#include <cstdlib>
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound
// & stable_sort, sort, reverse
#include <cmath>                            //sin(rad), abs, pow, sqrt, cbrt,  exp, log, log10, log2
#include <utility>                          // pair, make_pair
#include <map>                              // map
#include <set>                              // set
#include <vector>                           // vector
#include <queue>                            // queue, priority_queue
#include <stack>                            // stack
#include <list>                             // list
#include <deque>                            // deque
#include <iomanip>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,a,b) for(int i=(int)a;i<=(int)b;i++);
#define irep(i,n) for(int i=(int)n-1;i>=0;i--);

#define infi 2147483646
#define infl 9223372036854775806
//---------------------------------------------------
#define max_n 100000
struct card {
	char c;
	int v;
};

int n;
card c[max_n], ccpy[max_n], L[max_n / 2 + 1], R[max_n / 2 + 1];

void merge(int left, int mid, int right) {
	int r1 = mid - left, r2 = right - mid;
	rep(i, r1) { L[i] = ccpy[left + i]; }
	rep(i, r2) { R[i] = ccpy[mid + i]; }
	L[r1].v = R[r2].v = infi;

	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].v <= R[j].v) ccpy[k] = L[i++];
		else ccpy[k] = R[j++];
	}
}

void mergeSort(int left, int right) {
	if (right - left <= 1)return;
	else {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

int myPartition(int p, int r) {
	int x = c[r].v;
	int i = p - 1;

	for (int k = p; k < r;k++) {
		if (c[k].v <= x) {
			swap(c[k], c[++i]);
		}
	}
	swap(c[r], c[i + 1]);
	return i + 1;
}

void myQsort(int p, int r) {
	if (p < r) {
		int q = myPartition(p, r);
		myQsort(p, q - 1);
		myQsort(q + 1, r);
	}
}
int main() {
	//入力、初期化  (void)scanf("%d",&);
	(void)scanf("%d", &n);
	char ch[2]; int nm;
	rep(i, n) { (void)scanf("%s%d", ch, &nm); c[i].c = ccpy[i].c = ch[0]; c[i].v = ccpy[i].v = nm; }
	//処理
	mergeSort(0, n);
	myQsort(0, n - 1);

	int flag = 1;
	rep(i, n) { if (c[i].c != ccpy[i].c) { flag = 0; break; } }
	
	//出力
	if (flag)printf("Stable\n");
	else printf("Not stable\n");
	rep(i, n) { printf("%c %d\n", c[i].c, c[i].v); }
	
	return 0;
}
