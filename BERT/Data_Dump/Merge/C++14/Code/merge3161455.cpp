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


ll cnt=0;
void merge(int a[], int left, int mid, int right){
    int n1 = mid-left;
    int n2 = right-mid;
    
    int L[n1+1];
    for(int i=0; i<n1; ++i){
        L[i] = a[left+i];
    }
    int R[n2+1];
    for(int i=0; i<n2; ++i){
        R[i] = a[mid+i];
    }
    L[n1] = 1e9;
    R[n2] = 1e9;
    int i=0, j=0;
    
    for(int k=left; k<right; ++k){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
            cnt++;
        }else{
            a[k] = R[j];
            j++;
            cnt++;
        }
    }
}
void mergeSort(int a[], int left, int right){
    if(left+1<right){
        int mid = left+(right-left)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }else{
        return ;
    }
}
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[500010];
    REP(i, n) cin >> a[i];
    
    int left=0, right=n;
    mergeSort(a, left, right);
    
    for(int i=0; i<n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
	return 0;
}
