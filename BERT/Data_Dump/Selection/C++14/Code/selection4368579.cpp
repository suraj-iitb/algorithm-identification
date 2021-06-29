#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

class CommonIO {
public:
    CommonIO() {
        std::cin.tie(0);
        std::ios::sync_with_stdio(false);
    }
    ~CommonIO() {}

    template <class T>
    void scan(T &v) {
        std::cin >> v;
    }
    template <class T, class... Rest>
    void scan(T &v, Rest&... rest) {
        scan(v);
        scan(rest...);
    }

    template <class T>
    void print(T v) {
        std::cout << v;
    }
    template <class T>
    void print(std::vector<T> &v) {
        if (v.size() == 0) return;
        print(*v.begin());
        for (auto it = ++v.begin(); it != v.end(); ++it) {
            print(' ');
            print(*it);
        }
    }
    template <class T>
    void print(std::vector< std::vector<T> > &grid) {
        if (grid.size() == 0) return;
        print(*grid.begin());
        for (auto it = ++grid.begin(); it != grid.end(); ++it) {
            print('\n');
            print(*it);
        }
    }
    template <class T, class... Rest>
    void print(T v, Rest... rest) {
        print(v);
        print(' ');
        print(rest...);
    }

    template <class T>
    void printl(T v) {
        print(v);
        std::cout << '\n';
    }
    template <class T, class... Rest>
    void printl(T v, Rest... rest) {
        print(v);
        print(' ');
        printl(rest...);
    }
} io;


uint selectionSort(vector<int> &a, int N) {
  uint count = 0;
  int minj;
  REP(i, N) {
    minj = i;
    FOR(j, i, N) {
      if (a[j] < a[minj]) minj = j;
    }
    if (i != minj) {
      swap(a[i], a[minj]);
      ++count;
    }
  }
  
  return count;
}

int main() {
  int n; io.scan(n);
  vector<int> a(n);
  REP(i, n) io.scan(a[i]);
  
  uint count = selectionSort(a, n);
  io.printl(a);
  io.printl(count);
  return 0;
}

