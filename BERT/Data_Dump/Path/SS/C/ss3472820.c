#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
using ll = long long;

const ll INF = 100000LL * 10000LL * 100LL;

template<typename T, typename S>
class Pair {
  public:
    T first;
    S second;
    Pair(){}
    Pair(T first, S second){
      this->first = first;
      this->second = second;
    }
    Pair(const Pair<S, T>& other){
      this->first = other.first;
      this->second = other.second;
    }
    bool operator<=(const Pair<S, T>& other)const{
      return first <= other.first;
    }
    bool operator<(const Pair<S, T>& other)const{
      return first < other.first;
    }
    Pair &operator=(const Pair<S, T>& other){
      if(this != &other){
        first = other.first;
        second = other.second;
      }
      return *this;
    }
};

template <typename T>
class Vector {
  private:
  unsigned int end;
  unsigned int alloc;
  public:
  T* A;
  Vector(): end(0), alloc(1), A((T *)malloc(sizeof(T))){}
  // Vector(){
  //   end = 0;
  //   alloc = 1;
  //   A = (T *)malloc(sizeof(T));
  // }
  Vector(const unsigned int initial_size){
    end = initial_size;
    alloc = max((unsigned int)1, initial_size);
    A = (T *)malloc(sizeof(T) * initial_size);
  }
  Vector(const Vector &other){
    end = other.end;
    alloc = other.alloc;
    A = (T *)malloc(sizeof(T) * alloc);
    memcpy(A, other.A, sizeof(T) * alloc);
  }
  Vector &operator=(const Vector &other){
    if(this != &other){
      end = other.end;
      alloc = other.alloc;
      A = (T *)malloc(sizeof(T) * alloc);
      memcpy(A, other.A, sizeof(T) * alloc);
    }
    return *this;
  }
  unsigned int size()const{
    return end;
  }
  void push_back(T v){
    if(end < alloc){
    }else{
      if(alloc == 0 || A == NULL){
        A = (T *)malloc(sizeof(T));
        alloc++;
      }else{
      unsigned int nalloc = alloc * 2;
      T* nA = (T *)malloc(sizeof(T) * nalloc);
      memcpy(nA, A, sizeof(T) * end);
      free(A);
      A = nA;
      alloc = nalloc;
      }
    }
    A[end] = v;
    end++;
  }
  void pop_back(){
    if(end == 0) return;
    end--;
  }
  T &operator[](unsigned int idx){
    return A[idx];
  }
  ~Vector(){
    free(A);
  }
};


template <typename T>
class Heap {
  private:
  Vector<T> A;

  public:
  Heap(){
    A = Vector<T>(1);
  }

  void push(T v){
    unsigned int idx = A.size();
    A.push_back(v);

    while(1){
      if(idx == 1) break;
      unsigned int  par = idx / 2;
      if(A[par] < A[idx]) break;
      swap(A[idx], A[par]);
      idx = par;
    }
  };

  T top(){
    assert(A.size() > 1);
    return A[1];
  }
  T pop(){
    assert(A.size() > 1);
    T res = top();
    remove();
    return res;
  }
  bool empty(){
    return A.size() <= 1;
  }
  void remove(){
    T v = A[A.size() - 1];
    unsigned int idx = 1;
    A.pop_back();
    A[idx] = v;
    while(1){
      unsigned int  least = idx;
      unsigned int l = 2*idx, r = 2*idx+1;
      if(l < A.size() && A[l] <= A[least]){
        least = l;
      }
      if(r < A.size() && A[r] <= A[least]){
        least = r;
      }

      if(least == idx) break;
      swap(A[idx], A[least]);
      idx = least;
    }
  }
#ifdef EBUG
  void print(){
    for(int i = 1; i < A.size(); i++){cout << A[i] << " ";}
    cout << endl;
  }
#endif
};

#ifdef EBUG
void test_vector(){
  Vector<Vector<int>> v;
  for(int i = 0; i < 4; i++){
    Vector<int> w;
    for(int j = 0; j < 4; j++){
      w.push_back(i*4 + j);
    }
    v.push_back(w);
  }
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void test_heap(){
  const int size = 12;
  int elements[size] = {0, 6, 2, 7, 4, 1, 9, 8, 5, 9999, 6, 3};
  Heap<int> h;
  for(int i = 0; i < size; i++){
    h.push(elements[i]);
  }

  for(int i = 0; i < size; i++){
    cout << h.pop() << endl;
  }
}
#endif

int main(){
  ll V, E, r; cin >> V >> E >> r;
  Vector<Vector<Pair<ll, ll>>> G(V);
  for(ll i = 0; i < E; i++){
    ll s, t, d; cin >> s >> t>> d;
    Pair<ll, ll> p(t, d);
    G[s].push_back(p);
  }

  Vector<ll> d(V);
  for(ll i = 0; i < (ll)d.size(); i++){
    d[i] = INF;
  }

  Heap<Pair<ll, ll>> que;
  d[r] = 0;
  que.push(Pair<ll, ll>(0, r));
  while(!que.empty()){
    Pair<ll, ll> p = que.pop();
    ll v = p.second;
    if(d[v] < p.first) continue;
    for(ll i = 0; i < (ll)G[v].size(); i++){
      Pair<ll, ll> e = G[v][i];
      if(d[e.first] > d[v] + e.second){
        d[e.first] = d[v] + e.second;
        que.push(Pair<ll, ll>(d[e.first], e.first));
      }
    }
  }
  for(ll i = 0; i < (ll)d.size(); i++){
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}

