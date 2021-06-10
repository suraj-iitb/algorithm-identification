// C++ 14
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <cstring>

#define ll long long
#define Int ll
#define loop(__x, __start, __end) for(Int __x = __start; __x < __end; __x++)
#define loopdown(__x, __start, __end) for(Int __x = __start; __x > __end; __x--)
#define rep(__n) for(Int __x = 0; __x < __n; __x++)
#define span(__a,__x,__y) __a.begin()+__x,__a.begin()+__y
#define span_all(__a) __a.begin(),__a.end()
#define len(__x) (__x.size())
#define last(__x) (__x[__x.size()-1])

using namespace std;

struct Point {
  Int x, y;
  Point(Int x, Int y): x(x), y(y) {}
  Point(): x(0), y(0) {}

  Point operator + (Point v) { return Point(x + v.x, y + v.y); }
  Point operator - (Point v) { return Point(x - v.x, y - v.y); }
  bool operator == (const Point &v) const {
    return x == v.x && y == v.y;
  }
  bool operator< (const Point &p1) const {
    return x < p1.x && y < p1.y;
  }
};
ostream & operator << (ostream & out, Point const & v) {
  out << "Point(" << v.x << ", " << v.y << ')';
  return out;
}

istream & operator >> (istream & in, Point & v) {
  Int x, y;
  in >> x; in >> y; v.x = x; v.y = y;
  return in;
}

// Geometry

#define EPS 0.0000000001

class Vector2 {
public:
  double x, y;
  
  Vector2(double x = 0, double y = 0): x(x), y(y) {}
  
  Vector2 operator + (Vector2 v) { return Vector2(x + v.x, y + v.y); }
  Vector2 operator - (Vector2 v) { return Vector2(x - v.x, y - v.y); }
  Vector2 operator * (double k) { return Vector2(x * k, y * k); }
  Vector2 operator / (double k) { return Vector2(x / k, y / k); }
  
  double length() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  double dot (Vector2 v) { return x * v.x + y * v.y; }
  double cross (Vector2 v) { return x * v.y - y * v.x; }
  
  bool operator < (const Vector2 &v) const {
    return x != v.x ? x < v.x : y < v.y;
  }
  
  bool operator == (const Vector2 &v) const {
    return fabs(x - v.x) < EPS && fabs(y - v.y) < EPS;
  }
};

ostream & operator << (ostream & out, Vector2 const & v) { 
  out<< "Vector2(" << v.x << ", " << v.y << ')';
  return out;
}

istream & operator >> (istream & in, Vector2 & v) { 
  double x, y;
  in >> x;
  in >> y;
  v.x = x;
  v.y = y;
  return in;
}

struct Vertex {
  Int id, d;
  bool operator< (const Vertex &v2) const {
    return d == v2.d ? id > v2.id : d > v2.d;
  }
};
const Int INFTY = 10000000000000000;
Int V, E, R;
vector<vector<Vertex> > G(100001);
vector<Int> D(100001, INFTY);

void input() {
  cin >> V >> E >> R;
  Int v, u, d;
  rep(E) {
    cin >> v >> u >> d;
    G.at(v).push_back({ u, d });
  }
}

void solve() {
  priority_queue<Vertex> Q;
  Q.push({ R, 0 });
  D.at(R) = 0;

  while (Q.size()) {
    auto v = Q.top(); Q.pop();
    for (auto u: G.at(v.id)) {
      Int d = D.at(v.id) + u.d;
      if (D.at(u.id) <= d) continue;
      D.at(u.id) = d;
      Q.push(u);
    }
  }

  for (int i=0; i<V; i++) {
    if (D.at(i) == INFTY) cout << "INF" << endl;
    else cout << D.at(i) << endl;
  }
}

int main() {
  input();
  solve();
  return 0;
}

