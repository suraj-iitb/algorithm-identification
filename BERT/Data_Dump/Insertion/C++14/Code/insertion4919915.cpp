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

void insertion_sort(std::vector<int> & a, int n) {
    print(a, n);
    for(int i = 1; i < n; ++i) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a, n);
    }
}

int main() {

    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) std::cin >> a[i];

    insertion_sort(a, n);

    return 0;
}

