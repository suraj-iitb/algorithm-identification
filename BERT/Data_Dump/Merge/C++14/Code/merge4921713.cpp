#include <cstdio>
#include <cstdint>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <utility>
#include <math.h>
#include <stack>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


const long long mod = 1e9+7;

void chmod(long long &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

long long modpow(long long x, long long n){
    if(n==0) return 1;
    long long res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };



/* <-------------------------------------------------------------------------> */
/* <-------------------------------------------------------------------------> */
/* <-------------------------------------------------------------------------> */
/* <-------------------------------------------------------------------------> */

void print(std::vector<int> const & a, int n) {
    for(int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int merge(std::vector<int> & a, int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    const int INF = 2e9;
    std::vector<int> v1(n1+1, INF);
    std::vector<int> v2(n2+1, INF);
    for(int i = 0; i < n1; ++i) v1[i] = a[left+i];
    for(int i = 0; i < n2; ++i) v2[i] = a[mid+i];

    int cnt = 0;
    int i = 0, j = 0;
    for(int k = left; k < right; ++k) {
        cnt++;
        if(v1[i] <= v2[j]) {
            a[k] = v1[i];
            i++;
        }
        else {
            a[k] = v2[j];
            j++;
        }
    }
    return cnt;
}

int merge_sort(std::vector<int> & a, int n, int left, int right) {
    int cnt = 0;
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        cnt += merge_sort(a, n, left, mid);
        cnt += merge_sort(a, n, mid, right);
        cnt += merge(a, n, left, mid, right);
    }
    return cnt;
}

int main() {

    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];

    int cnt = merge_sort(a, n, 0, n);
    print(a, n);
    printf("%d\n", cnt);
}


