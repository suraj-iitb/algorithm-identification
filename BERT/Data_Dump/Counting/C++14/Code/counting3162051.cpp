#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <set>
#include <cstdio>
#include <bitset>
#include <functional>
#include <tuple>
#include <list>
#include <deque>
using namespace std;
typedef pair<int, int> P;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef vector<int> VI;


int A[2000010];
int C[10100];
int B[2000010];
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    int k=0;
    for(int i=0; i<n; ++i){
        cin >> A[i];
        k = max(k, A[i]);
    }
    for(int i=0; i<10001; ++i) C[i]=0;
    
    for(int i=0; i<n; ++i) C[A[i]]++;
    
    for(int i=1; i<10001; ++i) C[i] = C[i]+C[i-1];
    
    for(int i=n-1; i>=0; --i){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--; 
    }
    for(int i=0; i<n; ++i){
        if(i) cout << " ";
        cout << B[i];
    }
    cout << endl;
	return 0;
}
