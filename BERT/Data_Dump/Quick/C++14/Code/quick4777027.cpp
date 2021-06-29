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

struct Card {
  int num;
  char suit;
  
  Card(int _num, char _suit) : num(_num), suit(_suit) {}
};

int partition(std::vector<Card> & a, int p, int r) {
  Card x = a[r];
  int i = p - 1;
  for(int j = p; j < r; ++j) {
    if(a[j].num <= x.num) {
      ++i;
      std::swap(a[i], a[j]);
    }
  }
  std::swap(a[i + 1], a[r]);
  return i + 1;
}

void quickSort(std::vector<Card> & a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}

void merge(std::vector<Card> & a, int p, int mid, int r) {
  int n1 = mid - p;
  int n2 = r - mid;
  std::vector<Card> v1(n1 + 1, Card(1e9 + 1, 'z'));
  std::vector<Card> v2(n2 + 1, Card(1e9 + 1, 'z'));
  for(int i = 0; i < n1; ++i) v1[i] = a[p + i];
  for(int i = 0; i < n2; ++i) v2[i] = a[mid + i];
  int id1 = 0;
  int id2 = 0;
  for(int i = 0; i < r - p; ++i) {
    if(v1[id1].num <= v2[id2].num) a[p + i] = v1[id1++];
    else a[p + i] = v2[id2++];
  }
}

void mergeSort(std::vector<Card> & a, int p, int r) {
  if(p + 1 < r){
    int mid = (p + r) / 2;
    mergeSort(a, p, mid);
    mergeSort(a, mid, r);
    merge(a, p, mid, r);
  }
}

int main() {

    int n; scanf("%d\n", &n);
    std::vector<Card> a(n, Card(0, 'a'));
    std::vector<Card> b(n, Card(0, 'a'));

    for(int i = 0; i < n; ++i) {
      char c; int d;
      scanf(" %c %d", &c, &d);
      a[i] = Card(d, c);
      b[i] = a[i];
    }

    quickSort(a, 0, n - 1);
    mergeSort(b, 0, n);

    bool isStable = true;
    for(int i = 0; i < n; ++i) {
      if(a[i].suit != b[i].suit) { isStable = false; break; }
    }

    if(isStable) { printf("Stable\n"); }
    else { printf("Not stable\n"); }

    for(int i = 0; i < n; ++i) {
      printf("%c %d\n", a[i].suit, a[i].num);
    }

    return 0;
}

