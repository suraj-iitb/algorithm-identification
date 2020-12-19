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

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int selection_sort (vector<int> & a )
{
	int n = a.size();
	int res = 0;
	rep (i, n ){
		int mini = i;
		for (int j = i; j < n; j++ ){
			if (a[j] < a[mini] ){
				mini = j;
			} // end if
		} // end for
		if (i != mini ){
			swap (a[i], a[mini] );
			res++;
		} // end if
	} // end rep

	return res;
}

int main()
{
	int n;
	scanf ("%d", &n );
	vector<int> a (n, 0 );
	rep (i, n ) scanf ("%d", &a[i] );
	int cnt = selection_sort (a );
	rep (i, n ){
		printf ("%d", a[i] );
		i != n - 1 ? printf (" " ) : printf ("\n" );
	} // end rep
	printf ("%d\n", cnt );
	
	return 0;
}
