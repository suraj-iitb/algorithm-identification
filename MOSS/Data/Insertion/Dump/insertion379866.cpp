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
/*
	for j = 2 to length[A]
    do key = A[j]
    // insert A[j] into the sorted sequence A[1,...,j-1] 
    i = j - 1
    while i > 0 and A[i] > key
       do A[i+1] = A[i]
          i = i - 1
    A[i+1] = key
*/
void disp_array (vector<int> a )
{
	int n = a.size();
	rep (i, n ){
		cout << a[i] << (i != n - 1 ? ' ' : '\n' );
	} // end rep
}

int main()
{
//	cut here before submit 
//	freopen ("testcase.Insertion_Sort", "r", stdin );
	int n;
	scanf ("%d", &n );
	vector<int> A (n, 0 );

	rep (i, n ){
		scanf (" %d", &A[i] );
	} // end rep
	disp_array (A );
	for (int j = 1; j < n; j++ ){
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key ){
			swap (A[i+1], A[i] );
			i--;
		} // end while
		disp_array (A );
	} // end for

	return 0;
}
