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

  bool operator< (const Point &p1) {
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


/*
 * Usage:
 *   FloydWarshall fw(V);
 *   fw.addEdge(0, 1, 2);
 *   fw.addEdge(0, 2, 5);
 *   fw.apsp(); // O(V^3)
 *   fw.negative // -> true/false
 *   fw.distance(u, v) // -> long long
 */
class FloydWarshall {
public:
  const long long INFTY = (1L << 32);
  long long V;
  bool negative;
  bool done;

  FloydWarshall(long long V): V(V), negative(false), done(false), dist(V, vector<long long>(V, INFTY)) {
    loop(u,0,V) loop(v,0,V) {
      if (u == v) dist.at(u).at(v) = 0;
    }
  }

  long long distance(long long s, long long t) {
    return dist.at(s).at(t);
  }

  void addEdge(long long s, long long t, long long w, bool directed = false) {
    if (directed) {
      dist[s][t] = w;
      return;
    }

    dist[s][t] = dist[t][s] = w;
  }

  void apsp() {
    if (done) return;
    loop(k,0,V) {
      loop(u,0,V) {
        if (dist[u][k] == INFTY) continue;
        loop(v,0,V) {
          if (dist[k][v] == INFTY) continue;
          dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }

        if (dist[u][u] < 0) {
          done = negative = true;
          return;
        }
      }
    }
    done = true;
  }

private:
  vector<vector<long long> > dist;
};


#define MAX_V 101
#define MAX_E 9901
Int V, E;
Int S[MAX_E], T[MAX_E], W[MAX_E];


void input() {
  cin >> V >> E;
  loop(e,0,E) {
    cin >> S[e] >> T[e] >> W[e];
  }
}

void solve() {
  FloydWarshall fw(V);
  loop(e,0,E) fw.addEdge(S[e], T[e], W[e], true);
  fw.apsp();
  if (fw.negative) {
    cout << "NEGATIVE CYCLE" << endl;
    return;
  }

  loop(u,0,V) {
    loop(v,0,V) {
      if (fw.distance(u, v) == fw.INFTY) cout << "INF";
      else cout << fw.distance(u, v);
      if (v != V-1) cout << ' ';
    }
    cout << endl;
  }
}

int main() {
  input();
  solve();
  return 0;
}

