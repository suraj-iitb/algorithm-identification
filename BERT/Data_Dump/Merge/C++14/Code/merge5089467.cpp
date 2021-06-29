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
#define max_n 500000

//---------------------------------------------------
int n, cnt;
int A[max_n], L[max_n / 2 + 1], R[max_n / 2 + 1];

void merge(int left, int mid, int right) {
	int ran1 = mid - left, ran2 = right - mid;
	rep(i, ran1) L[i] = A[left + i];
	rep(i, ran2) R[i] = A[mid + i];
	L[ran1] = infi; R[ran2] = infi;

	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] >= R[j]) {
			A[k] = R[j++];
			cnt++;
		}
		else {
			A[k] = L[i++];
			cnt++;
		}
	}
}

void mergeSort(int left, int right) {
	if (right - left <= 1) return;
	else {
		int mid = (right + left) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}
int main() {
//入力、初期化	
	cnt = 0; (void)scanf("%d", &n);
	rep(i, n) { (void)scanf("%d", &A[i]); }
//処理
	mergeSort(0, n);
	rep(i, n) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);
//出力

	return 0;
}
