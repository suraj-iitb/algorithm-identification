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



int partition(pair<string, int> (&A)[100010], int p, int r){
    int x = A[r].second; // A中の最後の要素
    int i = p-1;
    for(int j=p; j<r; ++j){
        if(A[j].second<=x){ // A[j]よりxが大きい=A[j]はA[r]より小さい
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quicksort(pair<string, int> (&A)[100010], int p, int r){
    int q;
    if(p<r){
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    pair<string, int>A[100010];
    
    REP(i, n) {
        string s; int a; cin >> s >> a;
        A[i] = make_pair(s, a);
    }
    map<int, string> m1, m2;
    for(int i=0; i<n; ++i) m1[A[i].second]+=A[i].first;
    quicksort(A, 0, n-1);
    for(int i=0; i<n; ++i) m2[A[i].second]+=A[i].first;
    
    bool f = true;
    for(int i=0; i<n; ++i){
        if(m1[A[i].second]!=m2[A[i].second]) f=false;
    }
    if(f) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(int i=0; i<n; ++i){
        cout << A[i].first << " " << A[i].second << endl;
    }
	return 0;
}
