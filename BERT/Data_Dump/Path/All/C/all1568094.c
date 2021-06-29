#include <cstdio>
#include <cstdlib>

class FastIO {
public:
  void flush() {
    fflush(stdin);
    fflush(stdout);
  }
  FastIO& operator >> (int &right) {
    if( scanf("%d", &right) == EOF ) {
      fprintf(stderr, "cannot scanf().");
      exit(1);
    }
    return *this;
  }
  FastIO& operator >> (char &right) {
    if( scanf("%c", &right) == EOF ) {
      fprintf(stderr, "cannot scanf().");
      exit(1);
    }     
    return *this;
  }
  FastIO& operator >> (char right[]) {
    if( scanf("%s", right) == EOF ) {
      fprintf(stderr, "cannot scanf().");
      exit(1);
    }           
    return *this;
  }
  
  FastIO& operator << (const int& right) {
    printf("%d", right);
    return *this;
  }
  FastIO& operator << (int&& right) {
    printf("%d", right);
    return *this;
  }
  FastIO& operator << (const long& right) {
    printf("%ld", right);
    return *this;
  }
  FastIO& operator << (long&& right) {
    printf("%ld", right);
    return *this;
  }

  FastIO& operator << (const double& right) {
    printf("%.20lf", right);
    return *this;
  }
  FastIO& operator << (double&& right) {
    printf("%.20lf", right);
    return *this;
  }

  FastIO& operator << (const char right[]) {
    printf("%s", right);
    return *this;
  }
  
  FastIO& operator << (const char& right) {
    printf("%c", right);
    return *this;
  }
  FastIO& operator << (char&& right) {
    printf("%c", right);
    return *this;
  }
};

FastIO io;

template<typename T, typename U>
T Max(T arg1, U arg2) {
  T arg2T = static_cast<T>(arg2);
  if( arg1 < arg2T ) return arg2T;
  return arg1;
}

template<typename T, typename U>
T Min(T arg1, U arg2) {
  T arg2T = static_cast<T>(arg2);
  if( arg2T < arg1 ) return arg2T;
  return arg1;
}

#include <cstdint>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

constexpr int INF = (1 << 28);
constexpr long INFL = (1LL << 50);

template<size_t MAX_V>
class AdjacencyMatrix {
private:
  long w_[MAX_V][MAX_V];
  size_t size_;
public:
  AdjacencyMatrix(size_t size_)
    : size_(size_)
  {
    for(int i = 0; i < size_; ++i) {
      for(int j = 0; j < size_; ++j) {
        w_[i][j] = INFL;
      }
      w_[i][i] = 0;
    }
  }
  void set(int from, int to, int w) {
    w_[from][to] = w;
  }
  long& get(int from, int to) {
    return w_[from][to];
  }
  size_t size() {
    return size_;
  }
  bool negativeclosedpath() {
    for(int i = 0; i < size_; ++i) {
      if( w_[i][i] < 0 ) {
        return true;
      }
    }
    return false;
  }
};

template<size_t MAX_V>
void WarshallFloyd(AdjacencyMatrix<MAX_V>& arg) {
  for(int k = 0; k < arg.size(); ++k) {
    for(int i = 0; i < arg.size(); ++i) {
      for(int j = 0; j < arg.size(); ++j) {
        arg.get(i, j) = Min(arg.get(i, j), arg.get(i, k) + arg.get(k, j));
      }
    }
  }
}

class Solver {
private:
public:
  void solve() {
    int V, E;
    io >> V >> E;
    AdjacencyMatrix<128> matrix(V);
    for(int i = 0; i < E; ++i) {
      int s, t, d;
      io >> s >> t >> d;
      matrix.set(s, t, d);
    }
    WarshallFloyd(matrix);
    if( matrix.negativeclosedpath() ) {
      io << "NEGATIVE CYCLE" << '\n';
    }
    else {
      for(int i = 0; i < (int)matrix.size(); ++i) {
        for(int j = 0; j < (int)matrix.size() - 1; ++j) {
          long w = matrix.get(i, j);
          if( w <= INFL / 2 ) {
            io << w << ' ';
          }
          else {
            io << "INF ";
          }
        }
        long w = matrix.get(i, matrix.size() - 1);
        if( w <= INFL / 2 ) {
          io << w;
        }
        else {
          io << "INF";
        }
        io << '\n';
      }
    }
    return;
  }
};

int main() {

  Solver solver;
  solver.solve();

  return 0;
}
