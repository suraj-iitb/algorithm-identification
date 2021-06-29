#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <cstring>
#include <cstdlib>
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, sort, reverse, lower_bound, upper_bound
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

/*--- qsort(x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp); ---*/
int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return (-1);
	else if (*a > *b)
		return (1);
	return (0);
}


#define Prm 1046527
#define infi 2147483646
#define infl 9223372036854775806
#define max_a 100
#define max_m 100
#define max_n 2000000
//---------------------------------------------------
#define k 10000

int main() {
//入力、初期化	

	unsigned short* a, * b;

	int n, c[10001];
	(void)scanf("%d", &n);
	a = (unsigned short*)malloc(sizeof(short) * n + 1);
	b = (unsigned short*)malloc(sizeof(short) * n + 1);
	rep(i, n) { (void)scanf("%d", &a[i + 1]); }
//処理
	rep(i, k + 1) c[i] = 0;
	for (int i = 1; i <= n; i++) { c[a[i]]++; }
	for (int i = 1; i <= k; i++) { c[i] += c[i - 1]; }

	for (int j = n; j >= 1; j--) {
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
//出力
	rep(i, n) {
		if (i > 0)printf(" ");
		printf("%d", b[i + 1]);
	}
	printf("\n");
	return 0;
}
