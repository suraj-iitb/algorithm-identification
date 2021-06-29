#define _USE_MATH_DEFINES
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>
#include <numeric>
#include <list>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_M 100000000
#define MAX_N 10000
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

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


int SelectionSort(int x[], int n) {
	int mini;
	int cnt = 0;
	rep(i, n) {
		mini = i;
		for (int j = i; j < n; j++) {
			if (x[j] < x[mini]) {
				mini = j;
			}
		}

		swap(x[i], x[mini]);
		if (i != mini) cnt++;
	}
	return cnt;
}

int a[100];
int main() {
	int n;
	scanf("%d", &n);
	rep(i,n) scanf("%d", &a[i]);

	int ans = SelectionSort(a, n);
	rep(i, n-1) printf("%d ", a[i]);
	printf("%d\n%d\n",a[n-1],ans);

	return 0;
}
