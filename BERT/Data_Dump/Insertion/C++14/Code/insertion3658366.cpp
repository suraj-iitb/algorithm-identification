#ifdef LOCAL
#pragma GCC optimize ("O0")
#else
#pragma GCC optimize ("O3")
#endif
#include <bits/stdc++.h>

using namespace std;
using namespace std::placeholders;

using ll = long long;
const int INF = 1e9 + 7;
const ll INF_LL = 1e18 + 7;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(__name, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repFromTo(name, from, to) repFromUntil(name, from, to + 1)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)
#define reprFromTo(name, from, to) reprFromUntil(name, from, to + 1)

#define debugos cout
#ifdef LOCAL
#define debug(v) {printf("L%d %s > ",__LINE__,#v);debugos<<(v)<<endl;}
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:(v)){debugos<<e<<" ";}debugos<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){debugos<<(m)[x]<<" ";}debugos<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){debugos<<(m)[y][x]<<" ";}debugos<<endl;}}
#else
#define debug(v) {}
#define debugv(v) {}
#define debuga(m,w) {}
#define debugaa(m,h,w) {}
#endif

#define newl "\n"

#define all(iter) begin(iter), end(iter)

#if defined(_WIN32) || defined(_WIN64)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#elif defined(__GNUC__)
#else
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

template <class T> inline bool chmin(T& var, T x) {
  if (var > x) {
    var = x;
    return true;
  } else return false;
}
template <class T> inline bool chmax(T& var, T x) {
  if (var < x) {
    var = x;
    return true;
  } else return false;
}

class MyScanner {
  public:
    template<typename T> void input_integer(T& var) {
        var = 0; T sign = 1;
        int cc = getchar_unlocked();
        for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
            if (cc == '-') sign = -1;
        for (; '0' <= cc && cc <= '9'; cc = getchar_unlocked())
            var = (var << 3) + (var << 1) + cc - '0';
        var = var * sign;
    }
    inline int c() { return getchar_unlocked(); }
    inline MyScanner& operator>>(char& var) { var = c(); return *this; }
    inline MyScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
    inline MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; }
    inline MyScanner& operator>>(string& var) {
        int cc = getchar_unlocked();
        for (; !isvisiblechar(cc); cc = getchar_unlocked());
        for (; isvisiblechar(cc); cc = getchar_unlocked())
            var.push_back(cc);
        return *this;
    }
    inline operator int() {
      int n;
      *this >> n;
      return n;
    }
    inline operator ll() {
      ll n;
      *this >> n;
      return n;
    }
    private:
      inline int isvisiblechar(int c) {
        return 0x21 <= c && c <= 0x7E;
      }
};
class MyPrinter {
  public:
    template<typename T>
    void output_integer(T var) {
        if (var == 0) { putchar_unlocked('0'); return; }
        if (var < 0)
            putchar_unlocked('-'),
            var = -var;
        char stack[32]; int stack_p = 0;
        while (var)
            stack[stack_p++] = '0' + (var % 10),
            var /= 10;
        while (stack_p)
            putchar_unlocked(stack[--stack_p]);
    }
    inline MyPrinter& operator<<(char c) { putchar_unlocked(c); return *this; }
    inline MyPrinter& operator<<(int var) { output_integer<int>(var); return *this; }
    inline MyPrinter& operator<<(ll var) { output_integer<ll>(var); return *this; }
    inline MyPrinter& operator<<(char* str_p) { while (*str_p) putchar_unlocked(*(str_p++)); return *this; }
    inline MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar_unlocked(*(str_p++)); return *this; }
    inline MyPrinter& operator<<(const string& str) {
        const char* p = str.c_str();
        const char* l = p + str.size();
        while (p < l) putchar_unlocked(*p++);
        return *this;
    }
};
MyScanner IN;
MyPrinter OUT;

int main() {
  int n; IN >> n;
  int a[n]; rep(i, n) IN >> a[i];
  rep(i, n) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 and a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(i, n) OUT << a[i] << " \n"[i == n-1];
  }
}
