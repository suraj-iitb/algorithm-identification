#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define SENTINEL 1<<30

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int cnt;

void Merge(vector<int> & a, int left, int mid, int right )
{
	int n1 = mid - left;
	int n2 = right - mid;

	vector<int> L(n1 + 1, 0 ), R (n2 + 1, 0 );
	rep (i, n1 ) L[i] = a[left + i];
	rep (i, n2 ) R[i] = a[mid + i];

	L[n1] = SENTINEL;
	R[n2] = SENTINEL;

	int i = 0, j = 0;
	for (int k = left; k < right; k++ ){
		if (L[i] <= R[j] ){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		} // end if
		cnt++;	
	} // end for
}

void Merge_Sort (vector<int> &a, int left, int right )
{
	if (left + 1 < right ){
		int mid = (left + right )/2;
		Merge_Sort (a, left, mid );
		Merge_Sort (a, mid, right );
		Merge (a, left, mid, right );
	} // end if
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a (n, 0 );
	rep (i, n ) cin >> a[i];

	cnt = 0;
	Merge_Sort(a, 0, n );
	rep (i, n ) cout << a[i] << (i != n - 1 ? ' ' : '\n' );
	cout << cnt << endl;	
		
	return 0;
}
