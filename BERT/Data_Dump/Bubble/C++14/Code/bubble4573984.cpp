#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>


namespace vector {
  template<typename T, size_t dcap = 16ULL>
  class vec {
    size_t sz;
    size_t cap;
    T* a;
  public:
    vec() : sz(0), cap(dcap) {
      a = (T*)std::malloc(sizeof(T) * cap);
    }
    vec(size_t n) : sz(n), cap(dcap) {
      while (cap < sz) cap <<= 1;
      a = (T*)std::malloc(sizeof(T) * cap);
    }
    vec(size_t n, T v) : sz(n), cap(dcap) {
      while (cap < sz) cap <<= 1;
      a = (T*)std::malloc(sizeof(T) * cap);
      for (size_t i = 0; i < sz; i++) {
        a[i] = v;
      }
    }
    T& operator[](size_t i) {
      return a[i];
    }
    size_t size() const {
      return sz;
    }
    void output(std::ostream& out, char delim = ' ') const {
      for (size_t i = 0; i < sz; i++) {
        if (i) out << delim;
        out << a[i];
      }
    }
    friend std::ostream& operator<<(std::ostream& out, const vec& v) {
      v.output(out);
      return out;
    }
    void input(std::istream& in) {
      for (size_t i = 0; i < sz; i++) {
        in >> a[i];
      }
    }
    friend std::istream& operator>>(std::istream& in, vec& v) {
      v.input(in);
      return in;
    }
    ~vec() {
      std::free(a);
    }
  };
}

namespace algorithm {
  template<typename T>
  void insertion_sort(vector::vec<T>& v, bool verbose = false) {
    for (int i = 0, n = v.size(); i < n; i++) {
      int x = v[i], j;
      for (j = i - 1; j >= 0 && v[j] > x; j--) {
        v[j + 1] = v[j];
      }
      v[j + 1] = x;
      if (verbose) std::cout << v << std::endl;
    }
  }
  template<typename T>
  size_t bubble_sort(vector::vec<T>& v) {
    size_t cnt = 0;
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = n - 1; j > i; j--) {
        if (v[j] < v[j - 1]) {
          T t = v[j - 1];
          v[j - 1] = v[j];
          v[j] = t;
          cnt++;
        }
      }
    }
    return cnt;
  }
}

int main() {
  using namespace vector;
  using namespace algorithm;

  int N;
  std::cin >> N;

  vec<int> A(N);
  std::cin >> A;

  size_t cnt = bubble_sort(A);
  std::cout << A << std::endl << cnt << std::endl;
  
  return 0;
}
